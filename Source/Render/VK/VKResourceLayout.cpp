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
#include "VulkanInline.h"
#include "VulkanCommandBuffer.h"

#include <cassert>
#include <iostream>
#include <cstring>

namespace VK
{

ResourceLayout::ResourceLayout(Context* context):
		mContext(context)
{
	assert(mContext != nullptr);
	static const size_t max = 32;
	CreateDescriptorPool(max);
}

ResourceLayout::~ResourceLayout(void)
{
	mContext = nullptr;
	Vulkan::Release(mDescriptorPool);
	std::cout << "VK Destroy Resource Container" << std::endl;
}

void ResourceLayout::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mResourceLists.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mResourceLists.size());
	for(auto& list : mResourceLists)
	{
		DirtyState state = list.Update();
		mDirty = mDirty || (state == DirtyState::DIRTY_STATE_LAYOUT);
		descriptor_sets.push_back(list.GetDescriptorSet());
	}
	std::vector<uint32_t> offset;
	auto vk_cmd = list->GetCommandBufferVK();
	auto vk_layout = mCurrentLayout->GetPipelineLayoutVK();
	vk_cmd->BindDescriptorSets(vk_layout, descriptor_sets, offset);
	UpdatePipelineLayout();
}

ResourceList* ResourceLayout::GetResourceList(size_t index)
{
	const size_t size = mResourceLists.size();
	assert(index <= size);
	if (index == size)
	{
		mResourceLists.push_back(ResourceList(this));
	}
	return &mResourceLists.at(index);
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
	auto device = static_cast<Context*>(mContext)->GetDeviceVK();
	mDescriptorPool = Vulkan::DescriptorPool::New(device);
	mDescriptorPool->Create(max_allocate, descriptor_pool_sizes);
}

Vulkan::DescriptorSet* ResourceLayout::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mDescriptorPool != nullptr);
	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.resize(count);
	size_t size = count * sizeof(VkDescriptorSetLayoutBinding);
	std::memcpy(layout_bindings.data(), bindings, size);
	Vulkan::DescriptorSetLayout* layout = mDescriptorPool->GetLayout(layout_bindings);
	return mDescriptorPool->Allocate(layout);
}

PipelineLayout* ResourceLayout::UpdatePipelineLayout(void)
{
	for (auto layout : mPipelineLayouts)
	{
		auto& set_layouts = layout->GetDescriptorSetLayout();
		if (set_layouts == mDescriptorSetLayouts)
		{
			mCurrentLayout = layout;
			return mCurrentLayout;
		}
	}
	mCurrentLayout = new PipelineLayout(mContext);
	mPipelineLayouts.push_back(mCurrentLayout);
	mCurrentLayout->Create(mDescriptorSetLayouts);
	return mCurrentLayout;
}

} /* namespace VK */
