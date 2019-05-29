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
#include "VKFactory.h"
#include "VKDevice.h"
#include "VKPool.h"
#include "VKSampler.h"

#include "../../Platform/Vulkan/VulkanImage.h"
#include "../../Platform/Vulkan/VulkanImageView.h"
#include "../../Platform/Vulkan/VulkanSampler.h"
#include "../../Platform/Vulkan/VulkanBuffer.h"
#include "../../Platform/Vulkan/VulkanDescriptorSet.h"
#include "../../Platform/Vulkan/VulkanDescriptorPool.h"

#include <cassert>
#include <iostream>

namespace VK
{

BindingSet::BindingSet(Device* device):
		GHI::BindingSet(device)
{
}

BindingSet::~BindingSet(void)
{
	mDescriptorSet = nullptr;
	std::cout << "VK Destroy BindingSet" << std::endl;
}

void BindingSet::Create(void)
{
	AllocateDescriptorSet();
	WriteDescriptorSet();
	mValid = true;
}

void BindingSet::WriteDescriptorSet(void)
{
	const size_t size = mBindings.GetElementCount();
	assert(size > 0);

	std::vector<VkWriteDescriptorSet> descriptor_writes;
	descriptor_writes.reserve(size);

	std::vector<VkDescriptorImageInfo> image_infos(size);
	std::vector<VkDescriptorBufferInfo> buffer_infos(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.GetElementAt(bind);
		auto resource = binding.GetResource();
		auto resource_usage = resource->GetUsage();
		auto resource_type = resource->GetType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;

		switch(resource_type)
		{
		case GHI::ResourceType::IMAGE:
			image_infos.at(bind) = static_cast<Image*>(resource)->GetVulkanImage()->GetDescriptorInfo();;
			write.pImageInfo = &image_infos.at(bind);
			write.descriptorType = Image::GetDescriptorType(resource_usage);
			break;
		case GHI::ResourceType::BUFFER:
			buffer_infos.at(bind) = static_cast<Buffer*>(resource)->GetVulkanBuffer()->GetDescriptorInfo();
			write.pBufferInfo = &buffer_infos.at(bind);
			write.descriptorType = Buffer::GetDescriptorType(resource_usage);
			break;
		case GHI::ResourceType::SAMPLER:
			image_infos.at(bind) = static_cast<Sampler*>(resource)->GetVulkanSampler()->GetDescriptorInfo();
			write.pImageInfo = &image_infos.at(bind);
			write.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
			break;
		default:
			assert(false);
		}
		descriptor_writes.push_back(write);
	}
	assert(descriptor_writes.size() > 0);
	Vulkan::DescriptorSet::UpdateSets(mDescriptorSet->GetDevice(), descriptor_writes.size(), descriptor_writes.data());
}

void BindingSet::AllocateDescriptorSet(void)
{
	const size_t size = mBindings.GetElementCount();
	assert(size > 0);

	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.GetElementAt(bind);
		GHI::ShaderStage stage = binding.GetShaderStage();

		GHI::Resource* resource = binding.GetResource();
		GHI::UsageType resource_usage = resource->GetUsage();
		GHI::ResourceType resource_type = resource->GetType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);
		layout_bind.descriptorType = BindingSet::GetDescriptorType(resource_type, resource_usage);
		layout_bindings.push_back(layout_bind);
	}

	auto factory = mDevice->GetFactory();
	auto vk_pool = static_cast<Factory*>(factory)->GetPool();
	mDescriptorSet = vk_pool->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());
}

VkDescriptorType BindingSet::GetDescriptorType(GHI::ResourceType type, const GHI::UsageType& usage)
{
	VkDescriptorType descriptor_type = VK_DESCRIPTOR_TYPE_MAX_ENUM;
	switch(type)
	{
	case GHI::ResourceType::IMAGE:
		descriptor_type = Image::GetDescriptorType(usage);
		break;
	case GHI::ResourceType::BUFFER:
		descriptor_type = Buffer::GetDescriptorType(usage);
		break;
	case GHI::ResourceType::SAMPLER:
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
