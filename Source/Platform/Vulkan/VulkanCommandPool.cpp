/*
 * VulkanCommandPool.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanCommandPool.h"
#include "VulkanDevice.h"
#include "VulkanCommandBuffer.h"
#include "VulkanInline.h"
#include <cassert>

namespace Vulkan
{

CommandPool::CommandPool(Device* device):
		DeviceObject(device)
{
}

CommandPool::~CommandPool(void)
{
	for (auto buffer : m_buffers)
	{
		buffer->Destroy();
	}
	m_buffers.clear();
	VkDevice device = mDevice->GetHandle();
	vkDestroyCommandPool(device, m_pool, nullptr);
	m_pool = VK_NULL_HANDLE;
}

VkResult CommandPool::Create(uint32_t family)
{
	m_family = family;
	VkCommandPoolCreateInfo command_pool_create_info = CommandPool::CreateInfo();
	command_pool_create_info.queueFamilyIndex = family;
	return Create(&command_pool_create_info);
}

VkResult CommandPool::Create(const VkCommandPoolCreateInfo* info)
{
	mResult = vkCreateCommandPool(mDevice->GetHandle(), info, nullptr, &m_pool);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

CommandBuffer* CommandPool::Allocate(VkCommandBufferLevel level)
{
	Vulkan::CommandBuffer* buffer = Vulkan::CommandBuffer::New(mDevice);
	buffer->Create(this, level);
	m_buffers.push_back(buffer);
	return buffer;
}

VkCommandPoolCreateInfo CommandPool::CreateInfo(void)
{
	VkCommandPoolCreateInfo command_pool_create_info = {};
	command_pool_create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	command_pool_create_info.pNext = NULL;
	command_pool_create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	command_pool_create_info.queueFamilyIndex = 0;
	return command_pool_create_info;
}

} /* namespace Vulkan */
