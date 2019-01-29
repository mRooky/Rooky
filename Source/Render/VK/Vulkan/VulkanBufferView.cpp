/*
 * VulkanBufferView.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanBufferView.h"
#include "VulkanDevice.h"
#include "VulkanBuffer.h"
#include <cassert>

namespace Vulkan
{

BufferView::BufferView(Device* device):
		DeviceObject(device)
{
}

BufferView::~BufferView(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyBufferView(device, m_view, nullptr);
	m_view = VK_NULL_HANDLE;
	m_buffer = nullptr;
}

VkResult BufferView::Create(Buffer* buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range)
{
	m_buffer = buffer;
	VkBufferViewCreateInfo buffer_view_create_info = BufferView::CreateInfo();
	buffer_view_create_info.buffer = m_buffer->GetHandle();
	buffer_view_create_info.offset = offset;
	buffer_view_create_info.range = range;
	buffer_view_create_info.format = format;
	return Create(&buffer_view_create_info);
}

VkResult BufferView::Create(const VkBufferViewCreateInfo* info)
{
	mResult = vkCreateBufferView(mDevice->GetHandle(), info, nullptr, &m_view);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkBufferViewCreateInfo BufferView::CreateInfo(void)
{
	VkBufferViewCreateInfo buffer_view_create_info = {};
	buffer_view_create_info.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
	buffer_view_create_info.buffer = VK_NULL_HANDLE;
	buffer_view_create_info.format = VK_FORMAT_MAX_ENUM;
	buffer_view_create_info.offset = 0;
	buffer_view_create_info.range = 0;
	return buffer_view_create_info;
}

} /* namespace Vulkan */
