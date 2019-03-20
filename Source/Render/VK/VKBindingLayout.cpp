/*
 * VKResourceContainer.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKBindingLayout.h"
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
}

BindingLayout::~BindingLayout(void)
{
	Util::Release(mPipelineLayouts);
	Vulkan::Release(mDescriptorPool);
	std::cout << "VK Destroy Resource Container" << std::endl;
}

Render::PipelineLayout* BindingLayout::Update(void)
{
	UpdatePipelineLayout();
	return mCurrentLayout;
}

Render::BindingState* BindingLayout::CreateState(void)
{
	BindingState * state = new BindingState(this);
	mBindingStates.push_back(state);
	return state;
}

void BindingLayout::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mBindingStates.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mBindingStates.size());

	for(auto& state : mBindingStates)
	{
		auto vk_state = StaticCast(state);
		descriptor_sets.push_back(vk_state->GetDescriptorSet());
	}
	std::vector<uint32_t> offset;
	auto vk_pipeline_layout = StaticCast(mCurrentLayout);
	auto vulkan_command_buffer = list->GetVulkanCommandBuffer();
	auto vulkan_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	vulkan_command_buffer->BindDescriptorSets(vulkan_layout, descriptor_sets, offset);
}

void BindingLayout::SetBindingState(uint32_t index, BindingState* state)
{
	assert(index < mBindingStates.size());
	auto layout = mDescriptorSetLayouts.at(index);
	auto vk_state = StaticCast(state);
	auto state_layout = vk_state->GetDescriptorSet()->GetLayout();
	if (layout == state_layout)
	{
		mBindingStates.at(index) = state;
	}
	else
	{
		// log message future
		std::cout << "ResourceState does not match ResourceLayout !" << std::endl;
		assert(false);
	}
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
	auto device = StaticCast(mContext)->GetVulkanDevice();
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

void BindingLayout::UpdatePipelineLayout(void)
{
	assert(mBindingStates.size() > 0);
	std::vector<Vulkan::DescriptorSetLayout*> descriptor_layouts;
	descriptor_layouts.reserve(mBindingStates.size());

	for(auto& state : mBindingStates)
	{
		auto vk_state = StaticCast(state);
		vk_state->Update();
		Vulkan::DescriptorSetLayout* layout = vk_state->GetDescriptorSet()->GetLayout();
		descriptor_layouts.push_back(layout);
	}

	if (mCurrentLayout != nullptr)
	{
		auto& current_layouts = StaticCast(mCurrentLayout)->GetLayouts();
		if (current_layouts == descriptor_layouts)
		{
			return;
		}
	}
	mCurrentLayout = GetPipelineLayout(descriptor_layouts);
}

PipelineLayout* BindingLayout::GetPipelineLayout(const std::vector<Vulkan::DescriptorSetLayout*>& layouts)
{
	for (auto pipeline_layout : mPipelineLayouts)
	{
		auto& current_layouts = pipeline_layout->GetLayouts();
		if (current_layouts == layouts)
		{
			return pipeline_layout;
		}
	}

	auto pipeline_layout = new PipelineLayout(this);
	pipeline_layout->Create(layouts);
	mPipelineLayouts.push_back(pipeline_layout);
	return pipeline_layout;
}

} /* namespace VK */
