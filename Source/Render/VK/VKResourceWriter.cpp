/*
 * VKDescriptorPool.cpp
 *
 *  Created on: Feb 27, 2019
 *      Author: rookyma
 */

#include "VKResourceWriter.h"
#include "VKContext.h"
#include "VKCommandList.h"

#include "VulkanDescriptorPool.h"
#include "VulkanInline.h"
#include "VulkanCommandBuffer.h"
#include <cassert>
#include <cstring>

namespace VK
{

ResourceWriter::ResourceWriter(Context* context):
		mContext(context)
{
	assert(mContext != nullptr);
	static const size_t max = 32;
	CreateDescriptorPool(max);
}

ResourceWriter::~ResourceWriter(void)
{
	mContext = nullptr;
	Vulkan::Release(mDescriptorPool);
}

void ResourceWriter::CreateDescriptorPool(size_t max)
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

Vulkan::DescriptorSet* ResourceWriter::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mDescriptorPool != nullptr);
	std::vector<VkDescriptorSetLayoutBinding> layout_bindings;
	layout_bindings.resize(count);
	size_t size = count * sizeof(VkDescriptorSetLayoutBinding);
	std::memcpy(layout_bindings.data(), bindings, size);
	Vulkan::DescriptorSetLayout* layout = mDescriptorPool->GetLayout(layout_bindings);
	return mDescriptorPool->Allocate(layout);
}

void ResourceWriter::Binding(CommandList* list)
{
	assert(list != nullptr);
	assert(mPipelineLayout != nullptr);
	assert(mResourceSets.size() > 0);

	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(mResourceSets.size());

	for(auto& set : mResourceSets)
	{
		set.UpdateDescriptorSet();
		descriptor_sets.push_back(set.GetDescriptorSet());
	}
	std::vector<uint32_t> offset;
	auto vk_cmd = list->GetCommandBufferVK();
	vk_cmd->BindDescriptorSets(mPipelineLayout, descriptor_sets, offset);
}

ResourceSet* ResourceWriter::CreateResourceSet(void)
{
	mResourceSets.push_back(ResourceSet(this));
	ResourceSet* resource_set = &mResourceSets.back();
	return resource_set;
}

} /* namespace VK */
