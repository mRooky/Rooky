/*
 * VKResourceContainer.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKResourceLayout.h"
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

ResourceLayout::ResourceLayout(Context* context):
		Render::ResourceLayout(context)
{
	static const size_t max = 32;
	CreateDescriptorPool(max);
}

ResourceLayout::~ResourceLayout(void)
{
	Util::Release(mPipelineLayouts);
	Vulkan::Release(mDescriptorPool);
	std::cout << "VK Destroy Resource Container" << std::endl;
}

void ResourceLayout::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mResourceStates.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mResourceStates.size());

	for(auto& state : mResourceStates)
	{
		auto vk_state = StaticCast(state);
		descriptor_sets.push_back(vk_state->GetDescriptorSet());
	}
	std::vector<uint32_t> offset;
	auto vk_cmd = list->GetCommandBufferVK();
	auto vk_pipeline_layout = StaticCast(mCurrentLayout);
	auto vk_layout = vk_pipeline_layout->GetPipelineLayoutVK();
	vk_cmd->BindDescriptorSets(vk_layout, descriptor_sets, offset);
}

void ResourceLayout::SetResourceState(uint32_t index, ResourceState* state)
{
	assert(index < mResourceStates.size());
	auto layout = mDescriptorSetLayouts.at(index);
	auto vk_state = StaticCast(state);
	auto state_layout = vk_state->GetDescriptorSet()->GetLayout();
	if (layout == state_layout)
	{
		mResourceStates.at(index) = state;
	}
	else
	{
		// log message future
		std::cout << "ResourceState does not match ResourceLayout !" << std::endl;
		assert(false);
	}
}

void ResourceLayout::CreateDescriptorPool(size_t max)
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
	auto device = StaticCast(mContext)->GetDeviceVK();
	mDescriptorPool = Vulkan::DescriptorPool::New(device);
	mDescriptorPool->Create(max_allocate, descriptor_pool_sizes);
}

Vulkan::DescriptorSet* ResourceLayout::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mDescriptorPool != nullptr);
	Vulkan::DescriptorSetLayout* layout = mDescriptorPool->GetLayout(count, bindings);
	mDescriptorSetLayouts.push_back(layout);
	return mDescriptorPool->Allocate(layout);
}

void ResourceLayout::UpdatePipelineLayout(void)
{
	assert(mResourceStates.size() > 0);
	std::vector<Vulkan::DescriptorSetLayout*> descriptor_layouts;
	descriptor_layouts.reserve(mResourceStates.size());

	for(auto& state : mResourceStates)
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

PipelineLayout* ResourceLayout::GetPipelineLayout(const std::vector<Vulkan::DescriptorSetLayout*>& layouts)
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
