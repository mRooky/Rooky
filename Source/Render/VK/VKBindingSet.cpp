/*
 * ResourceList.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKBindingSet.h"
#include "VKShader.h"
#include "VKBuffer.h"
#include "VKImage.h"
#include "VKBindingLayout.h"

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

BindingSet::BindingSet(BindingLayout* layout):
		Render::BindingSet(layout)
{
}

BindingSet::~BindingSet(void)
{
	std::cout << "VK Destroy Resource List" << std::endl;
}

void BindingSet::Update(void)
{
	UpdateDescriptorSet();
	WriteDescriptorSet();
}

void BindingSet::SetBinding(uint32_t index, const Render::Binding& binding)
{
	bool set = mBindingMask.test(index);
	if (false == set)
	{
		mBindingMask.set(index);
		mBindings.at(index) = binding;
	}
	else
	{
		auto& old = mBindings.at(index);
		auto old_usage = old.GetResource()->GetUsage();
		auto new_usage = binding.GetResource()->GetUsage();
		if (old_usage != new_usage)
		{
			assert(false);
		}
		else
		{
			mBindings.at(index) = binding;
		}
	}
}

void BindingSet::WriteDescriptorSet(void)
{
	const size_t size = mBindings.size();
	assert(size > 0);

	std::vector<VkWriteDescriptorSet> descriptor_writes;
	descriptor_writes.reserve(size);

	std::vector<VkDescriptorImageInfo> image_infos(size);
	std::vector<VkDescriptorBufferInfo> buffer_infos(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.at(bind);
		auto resource = binding.GetResource();
		auto resource_usage = resource->GetUsage();
		auto resource_type = resource->GetType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;

		switch(resource_type)
		{
		case Render::ResourceType::RESOURCE_TYPE_IMAGE:
			BindingSet::SetImageInfo(&binding, &image_infos.at(bind));
			write.pImageInfo = &image_infos.at(bind);
			write.descriptorType = Image::GetDescriptorType(resource_usage.imageUsage);
			break;
		case Render::ResourceType::RESOURCE_TYPE_BUFFER:
			BindingSet::SetUniformInfo(&binding, &buffer_infos.at(bind));
			write.pBufferInfo = &buffer_infos.at(bind);
			write.descriptorType = Buffer::GetDescriptorType(resource_usage.bufferUsage);
			break;
		default:
			assert(false);
		}
		descriptor_writes.push_back(write);
	}
	assert(descriptor_writes.size() > 0);
	Vulkan::DescriptorSet::UpdateSets(mDescriptorSet->GetDevice(), descriptor_writes.size(), descriptor_writes.data());
}

void BindingSet::UpdateDescriptorSet(void)
{
	const size_t size = mBindings.size();
	assert(size > 0);

	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.at(bind);
		Render::ShaderStage stage = binding.GetShaderStage();

		Render::Resource* resource = binding.GetResource();
		Render::ResourceUsage resource_usage = resource->GetUsage();
		Render::ResourceType resource_type = resource->GetType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);
		layout_bind.descriptorType = BindingSet::GetDescriptorType(resource_type, resource_usage);
		layout_bindings.push_back(layout_bind);
	}

	auto layout = static_cast<BindingLayout*>(mLayout);
	mDescriptorSet = layout->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());
}

void BindingSet::SetImageInfo(const Render::Binding* binding, VkDescriptorImageInfo* info)
{
	assert(info != nullptr);
	Image* image = static_cast<Image*>(binding->GetResource());
	*info = image->GetVulkanImage()->GetDescriptorInfo();
}

void BindingSet::SetUniformInfo(const Render::Binding* binding, VkDescriptorBufferInfo* info)
{
	assert(info != nullptr);
	Buffer* buffer = static_cast<Buffer*>(binding->GetResource());
	*info = buffer->GetVulkanBuffer()->GetDescriptorInfo();
}

void BindingSet::SetSamplerInfo(const Render::Binding* binding, VkDescriptorImageInfo* info)
{
	assert(false);
}

VkDescriptorType BindingSet::GetDescriptorType(Render::ResourceType type, const Render::ResourceUsage& usage)
{
	VkDescriptorType descriptor_type = VK_DESCRIPTOR_TYPE_MAX_ENUM;
	switch(type)
	{
	case Render::ResourceType::RESOURCE_TYPE_IMAGE:
		descriptor_type = Image::GetDescriptorType(usage.imageUsage);
		break;
	case Render::ResourceType::RESOURCE_TYPE_BUFFER:
		descriptor_type = Buffer::GetDescriptorType(usage.bufferUsage);
		break;
	case Render::ResourceType::RESOURCE_TYPE_SAMPLER:
		descriptor_type = VK_DESCRIPTOR_TYPE_SAMPLER;
		break;
	default:
		assert(false);
		break;
	}
	assert(descriptor_type != VK_DESCRIPTOR_TYPE_MAX_ENUM);
	return descriptor_type;
}

} /* namespace VK */
