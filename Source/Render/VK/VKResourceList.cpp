/*
 * ResourceList.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKResourceList.h"
#include "VKResourceContainer.h"
#include "VKShader.h"
#include "VKBuffer.h"
#include "VKImage.h"

#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanBuffer.h"
#include "VulkanDescriptorSet.h"
#include "VulkanDescriptorPool.h"

#include <cassert>
#include <iostream>

namespace VK
{

ResourceList::ResourceList(ResourceContainer* container):
		mContainer(container)
{
	assert(mContainer != nullptr);
}

ResourceList::~ResourceList(void)
{
	std::cout << "VK Destroy Resource List" << std::endl;
}

void ResourceList::SetBinding(uint32_t bind, const Render::Binding& binding)
{
	assert(binding.IsValid());
	auto iterator = mResourceBindings.find(bind);
	if (iterator != mResourceBindings.end())
	{
		if (iterator->second != binding)
		{
			mDirty = true;
			iterator->second = binding;
		}
	}
	else
	{
		mDirty = true;
		mResourceBindings.insert(std::make_pair(bind, binding));
	}
}

DirtyState ResourceList::Update(void)
{
	DirtyState dirty_state = DirtyState::DIRTY_STATE_NONE;
	if (mDirty == true)
	{
		dirty_state = UpdateDescriptorSet();
		WriteDescriptorSet();
		mDirty = false;
	}
	return dirty_state;
}

void ResourceList::WriteDescriptorSet(void)
{
	const size_t size = mResourceBindings.size();
	assert(size > 0);

	std::vector<VkWriteDescriptorSet> descriptor_writes;
	descriptor_writes.reserve(size);

	std::vector<VkDescriptorImageInfo> image_infos(size);
	std::vector<VkDescriptorBufferInfo> buffer_infos(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mResourceBindings.at(bind);
		Render::Resource* resource = binding.GetResource();
		Render::ResourceType type = binding.GetResourceType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;
		write.descriptorType = ResourceList::GetDescriptorType(type);

		switch(type)
		{
		case Render::ResourceType::RESOURCE_TYPE_TEXTURE:
			ResourceList::SetImageInfo(resource, &image_infos.at(bind));
			write.pImageInfo = &image_infos.at(bind);
			break;
		case Render::ResourceType::RESOURCE_TYPE_UNIFORM:
			ResourceList::SetBufferInfo(resource, &buffer_infos.at(bind));
			write.pBufferInfo = &buffer_infos.at(bind);
			break;
		default:
			assert(false);
		}
		descriptor_writes.push_back(write);
	}
	assert(descriptor_writes.size() > 0);
	Vulkan::DescriptorSet::UpdateSets(mDescriptorSet->GetDevice(), descriptor_writes.size(), descriptor_writes.data());
}

DirtyState ResourceList::UpdateDescriptorSet(void)
{
	const size_t size = mResourceBindings.size();
	assert(size > 0);

	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mResourceBindings.at(bind);
		Render::ShaderStage stage = binding.GetShaderStage();
		Render::ResourceType type = binding.GetResourceType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);
		layout_bind.descriptorType = ResourceList::GetDescriptorType(type);
		layout_bindings.push_back(layout_bind);
	}

	Vulkan::DescriptorSetLayout* set_layout = nullptr;
	if (mDescriptorSet != nullptr)
	{
		set_layout = mDescriptorSet->GetLayout();
	}
	assert(layout_bindings.size() > 0);
	mDescriptorSet = mContainer->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());

	DirtyState dirty_state = DirtyState::DIRTY_STATE_RESOURCE;
	if (set_layout != mDescriptorSet->GetLayout())
	{
		dirty_state = DirtyState::DIRTY_STATE_LAYOUT;
	}
	return dirty_state;
}

void ResourceList::SetImageInfo(Render::Resource* resource, VkDescriptorImageInfo* info)
{
	assert(info != nullptr);
	assert(resource != nullptr);
	Image* image = static_cast<Image*>(resource);
	*info = image->GetImageVK()->GetDescriptorInfo();
}

void ResourceList::SetBufferInfo(Render::Resource* resource, VkDescriptorBufferInfo* info)
{
	assert(info != nullptr);
	assert(resource != nullptr);
	Buffer* buffer = static_cast<Buffer*>(resource);
	*info = buffer->GetBufferVK()->GetDescriptorInfo();
}

VkDescriptorType ResourceList::GetDescriptorType(Render::ResourceType type)
{
	switch(type)
	{
	case Render::ResourceType::RESOURCE_TYPE_COMMON:
		return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	case Render::ResourceType::RESOURCE_TYPE_BUFFER:
		return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	case Render::ResourceType::RESOURCE_TYPE_TEXTURE:
		return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
	case Render::ResourceType::RESOURCE_TYPE_UNIFORM:
		return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	case Render::ResourceType::RESOURCE_TYPE_SAMPLER:
		return VK_DESCRIPTOR_TYPE_SAMPLER;
	case Render::ResourceType::RESOURCE_TYPE_TARGET:
		return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
	default:
		assert(false);
		return VK_DESCRIPTOR_TYPE_MAX_ENUM;
	}
}

} /* namespace VK */
