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

	std::vector<VkDescriptorImageInfo> image_infos;
	image_infos.reserve(size);
	std::vector<VkDescriptorBufferInfo> buffer_infos;
	buffer_infos.reserve(size);

	for (size_t bind = 0; bind < size; ++bind)
	{
		auto& binding = mBindings.GetElementAt(bind);
		auto resource = binding.GetResource();
		auto resource_type = resource->GetType();

		VkWriteDescriptorSet write = Vulkan::DescriptorSet::WriteDescriptorSet();
		write.dstSet = mDescriptorSet->GetHandle();
		write.dstBinding = bind;
		write.descriptorCount = 1;

		if (resource_type == GHI::ResourceType::IMAGE)
		{
			auto image = static_cast<Image*>(resource);
			image_infos.push_back(image->GetVulkanImage()->GetDescriptorInfo());
			write.pImageInfo = &image_infos.back();
			write.descriptorType = image->GetDescriptorType();
		}
		else if (resource_type == GHI::ResourceType::BUFFER)
		{
			auto buffer = static_cast<Buffer*>(resource);
			buffer_infos.push_back(buffer->GetVulkanBuffer()->GetDescriptorInfo());
			write.pBufferInfo = &buffer_infos.back();
			write.descriptorType = buffer->GetDescriptorType();
		}
		else
		{
			auto sampler = static_cast<Sampler*>(resource);
			image_infos.push_back(sampler->GetVulkanSampler()->GetDescriptorInfo());
			write.pImageInfo = &image_infos.back();
			write.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
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
		GHI::ResourceType resource_type = resource->GetType();

		VkDescriptorSetLayoutBinding layout_bind = {};
		layout_bind.binding = bind;
		layout_bind.descriptorCount = 1;
		layout_bind.stageFlags = Shader::ConvertStage(stage);

		if (resource_type == GHI::ResourceType::IMAGE)
		{
			auto image = static_cast<Image*>(resource);
			layout_bind.descriptorType = image->GetDescriptorType();
		}
		else if (resource_type == GHI::ResourceType::BUFFER)
		{
			auto buffer = static_cast<Buffer*>(resource);
			layout_bind.descriptorType = buffer->GetDescriptorType();
		}
		else
		{
			layout_bind.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
		}

		layout_bindings.push_back(layout_bind);
	}

	auto factory = mDevice->GetFactory();
	auto vk_pool = static_cast<Factory*>(factory)->GetPool();
	mDescriptorSet = vk_pool->AllocateDescriptorSet(layout_bindings.size(), layout_bindings.data());
}

} /* namespace VK */
