/*
 * VulkanFence.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanFence.h"
#include "VulkanDevice.h"
#include <cassert>

namespace Vulkan
{

Fence::Fence(Device* device):
		DeviceObject(device)
{
}

Fence::~Fence(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyFence(device, m_fence, nullptr);
	m_fence = VK_NULL_HANDLE;
}

VkResult Fence::Create(void)
{
	VkFenceCreateInfo fence_create_info = Fence::CreateInfo();
	return Create(&fence_create_info);
}

VkResult Fence::Create(const VkFenceCreateInfo* info)
{
	mResult = vkCreateFence(mDevice->GetHandle(), info , nullptr, &m_fence);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkResult Fence::WaitFor(VkBool32 all, uint64_t timeout)
{
	assert(m_fence != VK_NULL_HANDLE);
	VkDevice device = mDevice->GetHandle();
	VkResult result = vkWaitForFences(device, 1, &m_fence, all, timeout);
	assert(result != VK_TIMEOUT);
	return result;
}

VkResult Fence::Reset(void)
{
	assert(m_fence != VK_NULL_HANDLE);
	VkDevice device = mDevice->GetHandle();
	VkResult result = vkResetFences(device, 1, &m_fence);
	assert(result == VK_SUCCESS);
	return result;
}

VkResult Fence::GetStatus(void) const
{
	assert(m_fence != VK_NULL_HANDLE);
	VkDevice device = mDevice->GetHandle();
	VkResult status = vkGetFenceStatus(device, m_fence);
	return status;
}

VkFenceCreateInfo Fence::CreateInfo(void)
{
	VkFenceCreateInfo fence_create_info = {};
	fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
	fence_create_info.pNext = nullptr;
	fence_create_info.flags = 0;
	return fence_create_info;
}

} /* namespace Vulkan */
