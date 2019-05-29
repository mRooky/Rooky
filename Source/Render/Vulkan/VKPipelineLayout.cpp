/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "VKDevice.h"
#include "VKPipelineLayout.h"
#include "VKBindingSet.h"

#include "../../Core/GHI/GHIBindingLayout.h"

#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanPipelineLayout.h"
#include "../../Platform/Vulkan/VulkanDescriptorSet.h"
#include "../../Platform/Vulkan/VulkanDescriptorSetLayout.h"

#include <cassert>

namespace VK
{

PipelineLayout::PipelineLayout(Device* device):
		GHI::PipelineLayout(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
	Vulkan::Release(mPipelineLayout);
}

void PipelineLayout::Create(GHI::BindingLayout* layout)
{
	assert(mBindingLayout == nullptr);
	mBindingLayout = layout;
	CreateVulkanPipelineLayout();
}

void PipelineLayout::CreateVulkanPipelineLayout(void)
{
	assert(mPipelineLayout == nullptr);
	const size_t count = mBindingLayout->GetSetCount();
	assert(count > 0);
	mDescriptorSetLayouts.clear();
	mDescriptorSetLayouts.reserve(count);

	for (size_t index = 0; index < count; ++index)
	{
		auto set = mBindingLayout->GetBindingSet(index);
		assert(set->IsValid());
		auto vk_set = static_cast<const BindingSet*>(set);
		Vulkan::DescriptorSet* vulkan_set = vk_set->GetDescriptorSet();
		Vulkan::DescriptorSetLayout* vulkan_layout = vulkan_set->GetLayout();
		mDescriptorSetLayouts.push_back(vulkan_layout);
	}

	Device* vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	mPipelineLayout = Vulkan::PipelineLayout::New(vulkan_device);
	mPipelineLayout->Create(mDescriptorSetLayouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
