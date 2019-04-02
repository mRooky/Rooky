/*
 * VulkanEvent.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanEvent.h"
#include "VulkanDevice.h"
#include <cassert>

namespace Vulkan
{

Event::Event(Device* device):
		DeviceObject(device)
{
}

Event::~Event(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyEvent(device, m_event, nullptr);
	m_event = VK_NULL_HANDLE;
}

VkResult Event::Create(void)
{
	VkEventCreateInfo event_create_info = Event::CreateInfo();
	return Create(&event_create_info);
}

VkResult Event::Create(const VkEventCreateInfo* info)
{
	mResult = vkCreateEvent(mDevice->GetHandle(), info, nullptr, &m_event);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkEventCreateInfo Event::CreateInfo(void)
{
	VkEventCreateInfo event_create_info = {};
	event_create_info.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
	event_create_info.pNext = nullptr;
	event_create_info.flags = 0;
	return event_create_info;
}

} /* namespace Vulkan */
