/*
 * VKPool.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: rookyma
 */

#include "VKPool.h"
#include "VKDevice.h"
#include "VKBuffer.h"
#include "VKInline.h"

#include "VulkanInline.h"
#include "VulkanDescriptorPool.h"
#include "VulkanDescriptorSet.h"
#include "VulkanCommandPool.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanBuffer.h"

#include "UtilityRelease.h"

#include <cassert>
#include <iostream>

namespace VK
{

Pool::Pool(Device& device):
		mDevice(device)
{
	CreateCommandPool();
	static const uint8_t max = 0xFF;
	CreateDescriptorPool(max);
}

Pool::~Pool(void)
{
	const size_t count = mBuffers.size();
	std::cout << "Release Recycle Buffer ..." << std::endl;
	Utility::Release(mBuffers);
	std::cout << "Released " << count << " Buffers !" << std::endl;
	Vulkan::Release(mCommandPool);
	Vulkan::Release(mDescriptorPool);
}

void Pool::CreateCommandPool(void)
{
	auto vulkan_device = mDevice.GetVulkanDevice();
	auto vulkan_physical = vulkan_device->GetPhysicalDevice();
	uint32_t family = vulkan_physical->GetFamily();
	mCommandPool = Vulkan::CommandPool::New(vulkan_device);
	mCommandPool->Create(family);
	mCommandPool->Allocate(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}

void Pool::CreateDescriptorPool(size_t max)
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
	auto vulkan_device = mDevice.GetVulkanDevice();
	mDescriptorPool = Vulkan::DescriptorPool::New(vulkan_device);
	mDescriptorPool->Create(max_allocate, descriptor_pool_sizes);
}

Vulkan::DescriptorSet* Pool::AllocateDescriptorSet(const std::vector<VkDescriptorSetLayoutBinding>& bindings)
{
	return AllocateDescriptorSet(bindings.size(), bindings.data());
}

Vulkan::DescriptorSet* Pool::AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(count > 0);
	assert(mDescriptorPool != nullptr);
	auto layout = mDescriptorPool->GetLayout(count, bindings);
	return mDescriptorPool->Allocate(layout);
}

Buffer* Pool::GetBuffer(size_t size, VkBufferUsageFlags usage)
{
	Buffer* buffer = SearchBuffer(size, usage);
	if (buffer == nullptr)
	{
		auto resource_usage = ConvertBufferUsageFlags(usage);
		resource_usage.allocate.CPUAccess = TRUE;
		buffer = new Buffer(&mDevice);
		buffer->Create(size, resource_usage);
		mBuffers.push_back(buffer);
	}
	assert(buffer != nullptr);
	return buffer;
}

Buffer* Pool::GetBuffer(size_t size, Render::ResourceUsage usage)
{
	Buffer* buffer = SearchBuffer(size, usage);
	if (buffer == nullptr)
	{
		buffer = new Buffer(&mDevice);
		buffer->Create(size, usage);
		mBuffers.push_back(buffer);
	}
	assert(buffer != nullptr);
	return buffer;
}

Buffer* Pool::SearchBuffer(size_t size, VkBufferUsageFlags usage)
{
	for (auto buffer : mBuffers)
	{
		size_t buffer_size = buffer->GetSize();
		if (buffer_size > size)
		{
			auto vulkan_buffer = buffer->GetVulkanBuffer();
			auto buffer_usage = vulkan_buffer->GetUsage();
			if ((usage & buffer_usage) == usage)
			{
				return buffer;
			}
		}
	}
	return nullptr;
}

Buffer* Pool::SearchBuffer(size_t size, Render::ResourceUsage usage)
{
	for (auto buffer : mBuffers)
	{
		size_t buffer_size = buffer->GetSize();
		if (buffer_size > size)
		{
			auto buffer_usage = buffer->GetUsage();
			if (buffer_usage == usage)
			{
				return buffer;
			}
		}
	}
	return nullptr;
}

} /* namespace VK */
