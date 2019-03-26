/*
 * VKResourceContainer.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKBindingLayout.h"
#include "VKBindingSet.h"
#include "VKContext.h"
#include "VKCommandList.h"
#include "VKPipelineLayout.h"

#include "VulkanDescriptorPool.h"
#include "VulkanDescriptorSet.h"
#include "VulkanInline.h"
#include "VulkanCommandBuffer.h"

#include "UtilRelease.h"

#include <cassert>
#include <iostream>
#include <cstring>

namespace VK
{

BindingLayout::BindingLayout(Context* context):
		Render::BindingLayout(context)
{
	static const size_t max = 32;
	CreateDescriptorPool(max);
	mDescriptorSets.reserve(MAX_BINDING_PER_SET);
}

BindingLayout::~BindingLayout(void)
{
	Vulkan::Release(mDescriptorPool);
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
		auto vk_set = static_cast<BindingSet*>(set);
		vk_set->Update();
		Vulkan::DescriptorSetLayout* layout = vk_set->GetDescriptorSet()->GetLayout();
		descriptor_layouts.push_back(layout);
	}

	mPipelineLayout = new PipelineLayout(this);
	static_cast<PipelineLayout*>(mPipelineLayout)->Create(descriptor_layouts);
}

Render::BindingSet* BindingLayout::CreateSet(void)
{
	BindingSet * set = new BindingSet(this);
	mBindingSets.push_back(set);
	return mBindingSets.back();
}

void BindingLayout::AppendBindingSet(const Render::BindingSet* set)
{
	assert(mDescriptorSets.size() < MAX_BINDING_PER_SET - 1);
	assert(set->IsValid());
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
	if (old_layout == new_layout)
	{
		mDescriptorSets.at(index) = vk_set->GetDescriptorSet();
	}
}

void BindingLayout::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mDescriptorSets.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mDescriptorSets.size());

	for(auto descriptor_set : mDescriptorSets)
	{
		descriptor_sets.push_back(descriptor_set);
	}

	std::vector<uint32_t> offset;
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(mPipelineLayout);
	auto vulkan_command_buffer = list->GetVulkanCommandBuffer();
	auto vulkan_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	vulkan_command_buffer->BindDescriptorSets(vulkan_layout, descriptor_sets, offset);
}

void BindingLayout::CreateDescriptorPool(size_t max)
{
	std::vector<VkDescriptorPoolSize> descriptor_pool_sizes;

	VkDescriptorPoolSize descriptor_pool_size = {};
	descriptor_pool_size.descriptorCount = max;

	for (uint32_t i = 0; i < VK_DESCRIPTOR_TYPE_RANGE_SIZE; ++i)
	{
		descriptor_pool_size.type = static_cast<VkDescriptorType>(i);
		descriptor_pool_sizes.push_back(descriptor_pool_size);
	}

	size_t max_allocate = VK_DESCRIPTOR_TYPE_RANGE_SIZE * max;
	auto device = static_cast<Context*>(mContext)->GetVulkanDevice();
	mDescriptorPool = Vulkan::DescriptorPool::New(device);
	mDescriptorPool->Create(max_allocate, descriptor_pool_sizes);
}

Vulkan::DescriptorSet* BindingLayout::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mDescriptorPool != nullptr);
	Vulkan::DescriptorSetLayout* layout = mDescriptorPool->GetLayout(count, bindings);
	mDescriptorSetLayouts.push_back(layout);
	return mDescriptorPool->Allocate(layout);
}

} /* namespace VK */
