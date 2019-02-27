/*
 * VKResourceSet.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "VKResourceSet.h"
#include "VKImage.h"
#include "VKSampler.h"
#include "VKResourceWriter.h"
#include "VKStructCompare.h"
#include "VKInline.h"
#include "VKBuffer.h"

#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanBuffer.h"
#include "VulkanDescriptorSet.h"
#include "VulkanDescriptorPool.h"

#include <cassert>
#include <algorithm>
#include <iostream>

namespace VK
{

ResourceSet::ResourceSet(ResourceWriter* writer):
		mWriter(writer)
{
	assert(mWriter != nullptr);
}

ResourceSet::~ResourceSet(void)
{
	mWriter = nullptr;
	mDescriptorSet = nullptr;
	for (auto& write : mWrites)
	{
		delete write.pImageInfo;
		write.pImageInfo = nullptr;
		delete write.pBufferInfo;
		write.pBufferInfo = nullptr;
	}
	mWrites.clear();
}

void ResourceSet::WriteSamplerImage(VkShaderStageFlagBits stage, uint32_t bind, Image* image, Sampler* sampler)
{
	VkDescriptorImageInfo image_info = {};
	if(image != nullptr)
	{
		Image* vk_image = static_cast<Image*>(image);
		image_info = vk_image->GetImageVK()->GetDescriptorInfo();
		image_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	}
	if (sampler != nullptr)
	{
		Sampler* vk_sampler = static_cast<Sampler*>(sampler);
		image_info.sampler = vk_sampler->GetSamplerVK()->GetHandle();
	}
	auto write = AppendOrReplaceInfo(bind, image_info);

	auto usage = image->GetUsage();
	ResourceSet::SetDescriptorType(usage, write);

	VkDescriptorSetLayoutBinding layout_bind = {};
	layout_bind.binding = bind;
	layout_bind.descriptorCount = 1;
	layout_bind.stageFlags = stage;
	layout_bind.descriptorType = write->descriptorType;
	AppendOrReplaceBinding(bind, layout_bind);
}

void ResourceSet::WriteUniformBuffer(VkShaderStageFlagBits stage, uint32_t bind, Buffer* buffer, size_t offset, size_t range)
{
	assert(range > 0);
	assert(buffer != nullptr);
	auto buffer_info = buffer->GetBufferVK()->GetDescriptorInfo();
	buffer_info.range = range;
	buffer_info.offset = offset;
	auto write = AppendOrReplaceInfo(bind, buffer_info);

	auto usage = buffer->GetUsage();
	ResourceSet::SetDescriptorType(usage, write);

	VkDescriptorSetLayoutBinding layout_bind = {};
	layout_bind.binding = bind;
	layout_bind.descriptorCount = 1;
	layout_bind.stageFlags = stage;
	layout_bind.descriptorType = write->descriptorType;
	AppendOrReplaceBinding(bind, layout_bind);
}

VkWriteDescriptorSet* ResourceSet::GetWriteSet(size_t bind)
{
	assert(bind <= mWrites.size());
	if (bind == mWrites.size())
	{
		mDirty = true;
		auto write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstBinding = bind;
		write.descriptorCount = 1;
		mWrites.push_back(write);
	}
	return &mWrites.at(bind);
}

VkDescriptorSetLayoutBinding* ResourceSet::GetLayoutBinding(size_t bind)
{
	assert(bind <= mLayoutbindings.size());
	if (bind == mLayoutbindings.size())
	{
		mDirty = true;
		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		mLayoutbindings.push_back(layout_bind);
	}
	return &mLayoutbindings.at(bind);
}

VkWriteDescriptorSet* ResourceSet::AppendOrReplaceInfo(size_t bind, const VkDescriptorImageInfo& info)
{
	assert(info.sampler != VK_NULL_HANDLE || info.sampler != VK_NULL_HANDLE);
	VkWriteDescriptorSet* write = GetWriteSet(bind);
	assert(write->pBufferInfo == nullptr);
	VkDescriptorImageInfo* info_ptr = nullptr;
	if (nullptr == write->pImageInfo)
	{
		mDirty = true;
		info_ptr = new VkDescriptorImageInfo;
		write->pImageInfo = info_ptr;
		info_ptr->sampler = info.sampler;
		info_ptr->imageView = info.imageView;
		info_ptr->imageLayout = info.imageLayout;
	}
	else
	{
		info_ptr = const_cast<VkDescriptorImageInfo*>(write->pImageInfo);
		if (!(*info_ptr == info))
		{
			mDirty = true;
			info_ptr->sampler = info.sampler;
			info_ptr->imageView = info.imageView;
			info_ptr->imageLayout = info.imageLayout;
		}
	}
	info_ptr = nullptr;
	return write;
}

VkWriteDescriptorSet* ResourceSet::AppendOrReplaceInfo(size_t bind, const VkDescriptorBufferInfo& info)
{
	VkWriteDescriptorSet* write = GetWriteSet(bind);
	assert(write->pImageInfo == nullptr);

	VkDescriptorBufferInfo* info_ptr = nullptr;
	if (nullptr == write->pImageInfo)
	{
		mDirty = true;
		info_ptr = new VkDescriptorBufferInfo;
		write->pBufferInfo = info_ptr;
		info_ptr->buffer = info.buffer;
		info_ptr->range = info.range;
		info_ptr->offset = info.offset;
	}
	else
	{
		info_ptr = const_cast<VkDescriptorBufferInfo*>(write->pBufferInfo);
		if (!(*info_ptr == info))
		{
			mDirty = true;
			info_ptr->buffer = info.buffer;
			info_ptr->range = info.range;
			info_ptr->offset = info.offset;
		}
	}
	info_ptr = nullptr;
	return write;
}

void ResourceSet::AppendOrReplaceBinding(size_t bind, const VkDescriptorSetLayoutBinding& binding)
{
	VkDescriptorSetLayoutBinding* exist = GetLayoutBinding(bind);
	if (!(*exist == binding))
	{
		mDirty = true;
		exist->binding = binding.binding;
		exist->descriptorType = binding.descriptorType;
		exist->descriptorCount = binding.descriptorCount;
		exist->stageFlags = binding.stageFlags;
	}
}

void ResourceSet::UpdateDescriptorSet(void)
{
	if (mDirty == true)
	{
		assert(mLayoutbindings.size() > 0);
		mDescriptorSet = mWriter->AllocateDescriptorSet(mLayoutbindings.size(), mLayoutbindings.data());
		assert(mWrites.size() > 0);
		Vulkan::DescriptorSet::UpdateSets(mDescriptorSet->GetDevice(), mWrites.size(), mWrites.data());
		mDirty = false;
	}
}

void ResourceSet::SetDescriptorType(Render::ImageUsage usage, VkWriteDescriptorSet* write)
{
	assert(write->pBufferInfo == nullptr);
	const VkDescriptorImageInfo* image_info = write->pImageInfo;
	assert(image_info != nullptr);
	if (image_info->sampler == VK_NULL_HANDLE)
	{
		if(image_info->imageView != VK_NULL_HANDLE)
		{
			write->descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
		}
		else
		{
			assert(false);
			std::cout << "Both Image and Sampler EMPTY !" << std::endl;
		}
	}
	else
	{
		if (image_info->imageView != VK_NULL_HANDLE)
		{
			write->descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		}
		else
		{
			write->descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
		}
	}
}

void ResourceSet::SetDescriptorType(Render::BufferUsage usage, VkWriteDescriptorSet* write)
{
	assert(write->pImageInfo == nullptr);
	const VkDescriptorBufferInfo* buffer_info = write->pBufferInfo;
	assert(buffer_info != nullptr);
	assert(buffer_info->buffer == VK_NULL_HANDLE);
	{
		write->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		if (usage.BufferUsageUniformDynamic == 1)
		{
			write->descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC;
		}
	}
}

} /* namespace VK */
