/*
 * VKResourceContainer.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "VKResourceContainer.h"
#include "VKContext.h"
#include "VKCommandList.h"

#include "VulkanDescriptorPool.h"
#include "VulkanInline.h"
#include "VulkanCommandBuffer.h"

#include <cassert>
#include <iostream>
#include <cstring>

namespace VK
{

ResourceContainer::ResourceContainer(Context* context):
		mContext(context)
{
	assert(mContext != nullptr);
	static const size_t max = 32;
	CreateDescriptorPool(max);
}

ResourceContainer::~ResourceContainer(void)
{
	mContext = nullptr;
	Vulkan::Release(mDescriptorPool);
	std::cout << "VK Destroy Resource Container" << std::endl;
}

void ResourceContainer::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mPipelineLayout != nullptr);
	assert(mResourceLists.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mResourceLists.size());

	for(auto& set : mResourceLists)
	{
		set.UpdateDescriptorSet();
		descriptor_sets.push_back(set.GetDescriptorSet());
	}
	std::vector<uint32_t> offset;
	auto vk_cmd = list->GetCommandBufferVK();
	vk_cmd->BindDescriptorSets(mPipelineLayout, descriptor_sets, offset);
}

ResourceList* ResourceContainer::CreateResourceList(void)
{
	mResourceLists.push_back(ResourceList(this));
	return &mResourceLists.back();
}

void ResourceContainer::CreateDescriptorPool(size_t max)
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

Vulkan::DescriptorSet* ResourceContainer::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mDescriptorPool != nullptr);
	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.resize(count);
	size_t size = count * sizeof(VkDescriptorSetLayoutBinding);
	std::memcpy(layout_bindings.data(), bindings, size);
	Vulkan::DescriptorSetLayout* layout = mDescriptorPool->GetLayout(layout_bindings);
	return mDescriptorPool->Allocate(layout);
}

} /* namespace VK */
