/*
 * VKResourceContainer.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKBindingLayout.h"
#include "VKBindingSet.h"
#include "VKCommandList.h"
#include "VKPipelineLayout.h"
#include "VKDevice.h"

#include "VulkanInline.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDescriptorSet.h"

#include <cassert>
#include <iostream>
#include <cstring>

namespace VK
{

BindingLayout::BindingLayout(Device* device):
		Render::BindingLayout(device)
{
	mDescriptorSets.reserve(MAX_BINDING_PER_SET);
}

BindingLayout::~BindingLayout(void)
{
	std::cout << "VK Destroy Resource Container" << std::endl;
}

void BindingLayout::Create(void)
{
	assert(mBindingSets.size() > 0);
	assert(mPipelineLayout == nullptr);
	std::vector<Vulkan::DescriptorSetLayout*> descriptor_layouts;
	descriptor_layouts.reserve(mBindingSets.size());

	for(auto& set : mBindingSets)
	{
		assert(set->IsValid());
		auto vk_set = static_cast<const BindingSet*>(set);
		Vulkan::DescriptorSetLayout* layout = vk_set->GetDescriptorSet()->GetLayout();
		descriptor_layouts.push_back(layout);
	}

	auto vk_device = static_cast<Device*>(mDevice);
	mPipelineLayout = new PipelineLayout(vk_device);
	static_cast<PipelineLayout*>(mPipelineLayout)->Create(this);
}

void BindingLayout::AppendBindingSet(const Render::BindingSet* set)
{
	assert(mDescriptorSets.size() < MAX_BINDING_PER_SET - 1);
	assert(set->IsValid());
	mBindingSets.push_back(set);
	const BindingSet* vk_set = static_cast<const BindingSet*>(set);
	mDescriptorSets.push_back(vk_set->GetDescriptorSet());
}

void BindingLayout::SetBindingSet(size_t index, const Render::BindingSet* set)
{
	assert(index < MAX_BINDING_PER_SET);
	assert(index < mDescriptorSets.size());
	const BindingSet* vk_set = static_cast<const BindingSet*>(set);
	auto old_layout = mDescriptorSets.at(index)->GetLayout();
	auto new_layout = vk_set->GetDescriptorSet()->GetLayout();
	assert(old_layout == new_layout);
	mBindingSets.at(index) = set;
	mDescriptorSets.at(index) = (old_layout == new_layout) ? vk_set->GetDescriptorSet() : VK_NULL_HANDLE;
}

void BindingLayout::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mDescriptorSets.size() > 0);
	std::vector<uint32_t> offset;
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(mPipelineLayout);
	auto vulkan_command_buffer = list->GetVulkanCommandBuffer();
	auto vulkan_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	vulkan_command_buffer->BindDescriptorSets(vulkan_layout, mDescriptorSets, offset);
}

} /* namespace VK */
