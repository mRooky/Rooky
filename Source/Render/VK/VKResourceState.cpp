/*
 * ResourceList.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include <VKResourceLayout.h>
#include <VKResourceState.h>
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

ResourceState::ResourceState(ResourceLayout* layout):
		Render::ResourceState(layout)
{
}

ResourceState::~ResourceState(void)
{
	std::cout << "VK Destroy Resource List" << std::endl;
}

void ResourceState::Update(void)
{
	UpdateDescriptorSet();
	WriteDescriptorSet();
}

void ResourceState::WriteDescriptorSet(void)
{
	const size_t size = mResources.size();
	assert(size > 0);

	std::vector<VkWriteDescriptorSet> descriptor_writes;
	descriptor_writes.reserve(size);

	std::vector<VkDescriptorImageInfo> image_infos(size);
	std::vector<VkDescriptorBufferInfo> buffer_infos(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& resource = mResources.at(bind);
		Render::ResourceType type = resource.GetResourceType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;
		write.descriptorType = ResourceState::GetDescriptorType(type);

		switch(type)
		{
		case Render::ResourceType::RESOURCE_TYPE_IMAGE:
			ResourceState::SetImageInfo(resource, &image_infos.at(bind));
			write.pImageInfo = &image_infos.at(bind);
			break;
		case Render::ResourceType::RESOURCE_TYPE_UNIFORM:
			ResourceState::SetUniformInfo(resource, &buffer_infos.at(bind));
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

void ResourceState::UpdateDescriptorSet(void)
{
	const size_t size = mResources.size();
	assert(size > 0);

	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& resource = mResources.at(bind);
		Render::ShaderStage stage = resource.GetShaderStage();
		Render::ResourceType type = resource.GetResourceType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);
		layout_bind.descriptorType = ResourceState::GetDescriptorType(type);
		layout_bindings.push_back(layout_bind);
	}

	auto layout = StaticCast(mLayout);
	mDescriptorSet = layout->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());
}

void ResourceState::SetImageInfo(const Render::Resource& resource, VkDescriptorImageInfo* info)
{
	assert(info != nullptr);
	Image* image = StaticCast(resource.GetImage());
	*info = image->GetImageVK()->GetDescriptorInfo();
}

void ResourceState::SetUniformInfo(const Render::Resource& resource, VkDescriptorBufferInfo* info)
{
	assert(info != nullptr);
	Buffer* buffer = StaticCast(resource.GetUniform());
	*info = buffer->GetBufferVK()->GetDescriptorInfo();
}

void ResourceState::SetSamplerInfo(const Render::Resource& resource, VkDescriptorImageInfo* info)
{
	assert(false);
}

VkDescriptorType ResourceState::GetDescriptorType(Render::ResourceType type)
{
	switch(type)
	{
	case Render::ResourceType::RESOURCE_TYPE_COMMON:
		return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
	case Render::ResourceType::RESOURCE_TYPE_BUFFER:
		return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
	case Render::ResourceType::RESOURCE_TYPE_IMAGE:
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
