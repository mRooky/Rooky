/*
 * VulkanBuffer.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanBuffer.h"
#include "VulkanDevice.h"
#include "VulkanImage.h"
#include "VulkanDeviceMemory.h"
#include "VulkanCommandBuffer.h"
#include "VulkanPhysicalDevice.h"
#include <cassert>
#include <cstring>

namespace Vulkan
{

Buffer::Buffer(Device* device) :
		Resource(device)
{
}

Buffer::~Buffer(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyBuffer(device, m_buffer, nullptr);
	m_buffer = VK_NULL_HANDLE;
}

VkResult Buffer::Create(VkDeviceSize size, VkBufferUsageFlags usage)
{
	m_size = size;
	m_usage = usage;
	uint32_t family = mDevice->GetPhysicalDevice()->GetFamily();
	VkBufferCreateInfo buffer_create_info = Vulkan::Buffer::CreateInfo();
	buffer_create_info.size = size;
	buffer_create_info.usage = usage;
	buffer_create_info.queueFamilyIndexCount = 1;
	buffer_create_info.pQueueFamilyIndices = &family;
	return Create(&buffer_create_info);
}

VkResult Buffer::Create(const VkBufferCreateInfo* info)
{
	assert(info != nullptr);
	mResult = vkCreateBuffer(mDevice->GetHandle(), info, nullptr, &m_buffer);
	assert(mResult == VK_SUCCESS);
	vkGetBufferMemoryRequirements(mDevice->GetHandle(), m_buffer, &mRequirement);
	return mResult;
}

void Buffer::WriteData(VkDeviceSize offset, VkDeviceSize size, const void* src)
{
	assert(mMemory != nullptr);
	void* ptr = mMemory->Map(offset, size);
	assert(ptr != nullptr);
	std::memcpy(ptr, src, size);
	mMemory->Flush(offset, size);
	mMemory->Unmap();
}

void Buffer::ReadData(VkDeviceSize offset, VkDeviceSize size, void* dst)
{
	assert(mMemory != nullptr);
	void* ptr = mMemory->Map(offset, size);
	assert(ptr != nullptr);
	std::memcpy(dst, ptr, size);
	mMemory->Unmap();
}

VkResult Buffer::BindMemory(DeviceMemory* memory, VkDeviceSize offset)
{
	VkDevice device = mDevice->GetHandle();
	VkDeviceMemory handle = memory->GetHandle();
	VkResult result = vkBindBufferMemory(device, m_buffer, handle, offset);
	assert(result == VK_SUCCESS);
	mMemory = memory;
	mOffset = offset;
	return result;
}

VkDescriptorBufferInfo Buffer::GetDescriptorInfo(void) const
{
	VkDescriptorBufferInfo descriptor_buffer_info = {};
	descriptor_buffer_info.buffer = m_buffer;
	return descriptor_buffer_info;
}

VkBufferCreateInfo Buffer::CreateInfo(void)
{
	VkBufferCreateInfo buffer_create_info = {};
	buffer_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	buffer_create_info.pNext = nullptr;
	buffer_create_info.flags = 0;
	buffer_create_info.size = 0;
	buffer_create_info.usage = VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
	buffer_create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	buffer_create_info.queueFamilyIndexCount = 0;
	buffer_create_info.pQueueFamilyIndices = nullptr;
	return buffer_create_info;
}

} /* namespace Vulkan */
