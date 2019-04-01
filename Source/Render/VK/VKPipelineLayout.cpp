/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "VKBindingLayout.h"
#include "VKDevice.h"
#include "VKPipelineLayout.h"
#include "VulkanInline.h"
#include "VulkanPipelineLayout.h"
#include "VulkanDescriptorSet.h"
#include "VulkanDescriptorSetLayout.h"

#include <cassert>

namespace VK
{

PipelineLayout::PipelineLayout(Device* device):
		Render::PipelineLayout(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
	Vulkan::Release(mPipelineLayout);
}

void PipelineLayout::Create(Render::BindingLayout* layout)
{
	assert(mBindingLayout == nullptr);
	mBindingLayout = layout;
	CreateVulkanPipelineLayout();
}

void PipelineLayout::CreateVulkanPipelineLayout(void)
{
	assert(mPipelineLayout == nullptr);
	const size_t count = mBindingLayout->GetStateCount();
	assert(count > 0);
	std::vector<Vulkan::DescriptorSetLayout*> descriptor_layouts;
	descriptor_layouts.reserve(count);
	for (size_t index = 0; index < count; ++index)
	{
		auto set = mBindingLayout->GetBindingSet(index);
		assert(set->IsValid());
		auto vk_set = static_cast<const BindingSet*>(set);
		Vulkan::DescriptorSetLayout* layout = vk_set->GetDescriptorSet()->GetLayout();
		descriptor_layouts.push_back(layout);
	}

	auto device = mBindingLayout->GetDevice();
	Vulkan::Device* vulkan_device = static_cast<Device*>(device)->GetVulkanDevice();
	mPipelineLayout = Vulkan::PipelineLayout::New(vulkan_device);
	mPipelineLayout->Create(descriptor_layouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
