/*
 * VulkanDevice.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"
#include <cassert>

namespace Vulkan
{

Device::Device(PhysicalDevice* physical) :
		m_physicalDevice(physical)
{
}

Device::~Device(void)
{
	for (auto queue: m_queues)
	{
		queue->Destroy();
	}
	m_queues.clear();
	mResult = vkDeviceWaitIdle(m_device);
	assert(mResult == VK_SUCCESS);
	vkDestroyDevice(m_device, nullptr);
	m_device = VK_NULL_HANDLE;
	m_physicalDevice = nullptr;
}

VkResult Device::Create(const VkDeviceCreateInfo* info)
{
	assert(VK_SUCCESS == m_physicalDevice->GetResult());
	VkPhysicalDevice handle = m_physicalDevice->GetHandle();
	mResult = vkCreateDevice(handle, info, nullptr, &m_device);
	assert(VK_NULL_HANDLE != m_device);
	assert(mResult == VK_SUCCESS);
	for(uint32_t i = 0; i < info->queueCreateInfoCount; ++i)
	{
		auto queue_create_info = info->pQueueCreateInfos + i;
		for(uint32_t index = 0; index < queue_create_info->queueCount; ++index)
		{
			Queue* queue = Queue::New(this);
			queue->Create(queue_create_info->queueFamilyIndex, index);
			m_queues.push_back(queue);
		}
	}
	return mResult;
}

Queue* Device::GetQueue(uint32_t family, uint32_t index)
{
	for(auto queue : m_queues)
	{
		if(family == queue->GetFamily() &&	index == queue->GetIndex())
		{
			return queue;
		}
	}
	assert(false);
	return nullptr;
}

VkDeviceCreateInfo Device::CreateInfo(void)
{
	VkDeviceCreateInfo device_create_info = {};
	device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	device_create_info.pNext = nullptr;
	device_create_info.flags = 0;
	device_create_info.queueCreateInfoCount = 0;
	device_create_info.pQueueCreateInfos = nullptr;
	device_create_info.enabledLayerCount = 0;
	device_create_info.ppEnabledLayerNames = nullptr;
	device_create_info.enabledExtensionCount = 0;
	device_create_info.ppEnabledExtensionNames = nullptr;
	device_create_info.pEnabledFeatures = nullptr;
	return device_create_info;
}

} /* namespace Vulkan */
