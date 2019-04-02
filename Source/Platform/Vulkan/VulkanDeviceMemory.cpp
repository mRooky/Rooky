/*
 * VulkanDeviceMemory.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanDeviceMemory.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanResource.h"
#include <cassert>

namespace Vulkan
{

DeviceMemory::DeviceMemory(Device* device):
		DeviceObject(device)
{
}

DeviceMemory::~DeviceMemory(void)
{
	VkDevice device = mDevice->GetHandle();
	vkFreeMemory(device, m_memory, nullptr);
	m_memory = VK_NULL_HANDLE;
}

VkResult DeviceMemory::Allocate(Resource* resource , VkMemoryPropertyFlags properties)
{
	VkMemoryRequirements requirements = resource->GetMemoryRequirements();
	return Allocate(requirements, properties);
}

VkResult DeviceMemory::Allocate(VkDeviceSize size, uint32_t index, VkMemoryPropertyFlags properties)
{
	m_typeIndex = index;
	mProperties = properties;
	VkMemoryAllocateInfo memory_allocate_info = DeviceMemory::AllocateInfo();
	memory_allocate_info.allocationSize = size;
	memory_allocate_info.memoryTypeIndex = index;
	return Allocate(&memory_allocate_info);
}

VkResult DeviceMemory::Allocate(const VkMemoryRequirements& requirements, VkMemoryPropertyFlags properties)
{
	PhysicalDevice* physical = mDevice->GetPhysicalDevice();
	uint32_t index = physical->GetMemoryTypeIndex(requirements.memoryTypeBits, properties);
	return Allocate(requirements.size, index, properties);
}

VkResult DeviceMemory::Allocate(const VkMemoryAllocateInfo* info)
{
	mResult = vkAllocateMemory(mDevice->GetHandle(), info, nullptr, &m_memory);
	assert(mResult == VK_SUCCESS);
	m_size = info->allocationSize;
	m_typeIndex = info->memoryTypeIndex;
	return mResult;
}

void* DeviceMemory::Map(VkDeviceSize offset, VkDeviceSize size)
{
	assert(mProperties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
	void* ptr = nullptr;
	if (mProperties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
	{
		VkDevice device = mDevice->GetHandle();
		mResult = vkMapMemory(device, m_memory, offset, size, 0, &ptr);
		assert(mResult == VK_SUCCESS);
	}
	return ptr;
}

void DeviceMemory::Unmap(void)
{
	if (mProperties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
	{
		VkDevice device = mDevice->GetHandle();
		vkUnmapMemory(device, m_memory);
	}
}

void DeviceMemory::Flush(VkDeviceSize offset, VkDeviceSize size)
{
	VkMemoryPropertyFlags property_flags = mProperties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	if(!property_flags)
	{
		assert(size > 0);
		VkDevice device = mDevice->GetHandle();
		VkMappedMemoryRange range = DeviceMemory::MappedRange();
		range.offset = offset;
		range.size = size;
		range.memory = m_memory;
		mResult = vkFlushMappedMemoryRanges(device, 1, &range);
		assert(mResult == VK_SUCCESS);
	}
}

void DeviceMemory::Flush(const std::vector<VkMappedMemoryRange>& ranges)
{
	VkMemoryPropertyFlags property_flags = mProperties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	if(!property_flags)
	{
		VkDevice device = mDevice->GetHandle();
		mResult = vkFlushMappedMemoryRanges(device, ranges.size(), ranges.data());
		assert(mResult == VK_SUCCESS);
	}
}

VkMemoryAllocateInfo DeviceMemory::AllocateInfo(void)
{
	VkMemoryAllocateInfo memory_allocate_info = {};
	memory_allocate_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	memory_allocate_info.pNext = nullptr;
	memory_allocate_info.allocationSize = 0;
	memory_allocate_info.memoryTypeIndex = 0;
	return memory_allocate_info;
}

VkMappedMemoryRange DeviceMemory::MappedRange(void)
{
	VkMappedMemoryRange range = {};
	range.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
	range.pNext = nullptr;
	return range;
}

} /* namespace Vulkan */
