/*
 * ResourceList.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKBindingState.h"
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

BindingState::BindingState(BindingLayout* layout):
		Render::BindingState(layout)
{
}

BindingState::~BindingState(void)
{
	std::cout << "VK Destroy Resource List" << std::endl;
}

void BindingState::Update(void)
{
	UpdateDescriptorSet();
	WriteDescriptorSet();
}

void BindingState::WriteDescriptorSet(void)
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
		Render::ResourceFlag type = binding.GetResourceType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;
		write.descriptorType = BindingState::GetDescriptorType(type);

		switch(type)
		{
		case Render::ResourceFlag::RESOURCE_TYPE_IMAGE:
			BindingState::SetImageInfo(binding, &image_infos.at(bind));
			write.pImageInfo = &image_infos.at(bind);
			break;
		case Render::ResourceFlag::RESOURCE_TYPE_UNIFORM:
			BindingState::SetUniformInfo(binding, &buffer_infos.at(bind));
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

void BindingState::UpdateDescriptorSet(void)
{
	const size_t size = mBindings.size();
	assert(size > 0);

	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.at(bind);
		Render::ShaderStage stage = binding.GetShaderStage();
		Render::ResourceFlag type = binding.GetResourceType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);
		layout_bind.descriptorType = BindingState::GetDescriptorType(type);
		layout_bindings.push_back(layout_bind);
	}

	auto layout = static_cast<BindingLayout*>(mLayout);
	mDescriptorSet = layout->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());
}

void BindingState::SetImageInfo(const Render::Binding& binding, VkDescriptorImageInfo* info)
{
	assert(info != nullptr);
	Image* image = static_cast<Image*>(binding.GetResource());
	*info = image->GetVulkanImage()->GetDescriptorInfo();
}

void BindingState::SetUniformInfo(const Render::Binding& binding, VkDescriptorBufferInfo* info)
{
	assert(info != nullptr);
	Buffer* buffer = static_cast<Buffer*>(binding.GetResource());
	*info = buffer->GetVulkanBuffer()->GetDescriptorInfo();
}

void BindingState::SetSamplerInfo(const Render::Binding& binding, VkDescriptorImageInfo* info)
{
	assert(false);
}

VkDescriptorType BindingState::GetDescriptorType(Render::ResourceFlag type)
{
	switch(type)
	{
	case Render::ResourceFlag::RESOURCE_TYPE_COMMON:
		return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	case Render::ResourceFlag::RESOURCE_TYPE_BUFFER:
		return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	case Render::ResourceFlag::RESOURCE_TYPE_IMAGE:
		return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
	case Render::ResourceFlag::RESOURCE_TYPE_UNIFORM:
		return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	case Render::ResourceFlag::RESOURCE_TYPE_SAMPLER:
		return VK_DESCRIPTOR_TYPE_SAMPLER;
	case Render::ResourceFlag::RESOURCE_TYPE_TARGET:
		return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
	default:
		assert(false);
		return VK_DESCRIPTOR_TYPE_MAX_ENUM;
	}
}

} /* namespace VK */
