/*
 * VulkanSemaphore.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanSemaphore.h"
#include "VulkanDevice.h"
#include <cassert>

namespace Vulkan
{

Semaphore::Semaphore(Device* device):
		DeviceObject(device)
{
}

Semaphore::~Semaphore(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroySemaphore(device, m_semaphore, nullptr);
	m_semaphore = VK_NULL_HANDLE;
}

VkResult Semaphore::Create(void)
{
	VkSemaphoreCreateInfo semaphore_create_info = Semaphore::CreateInfo();
	return Create(&semaphore_create_info);
}

VkResult Semaphore::Create(const VkSemaphoreCreateInfo* info)
{
	mResult = vkCreateSemaphore(mDevice->GetHandle(), info, nullptr, &m_semaphore);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkSemaphoreCreateInfo Semaphore::CreateInfo(void)
{
	VkSemaphoreCreateInfo semaphore_create_info = {};
	semaphore_create_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	semaphore_create_info.pNext = nullptr;
	semaphore_create_info.flags = 0;
	return semaphore_create_info;
}

} /* namespace Vulkan */
