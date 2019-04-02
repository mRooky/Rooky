/*
 * VulkanQueue.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanQueue.h"
#include "VulkanDevice.h"
#include "VulkanFence.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanCommandBuffer.h"
#include <cassert>

namespace Vulkan
{

Queue::Queue(Device* device):
		DeviceObject(device)
{
}

Queue::~Queue(void)
{
	m_queue = VK_NULL_HANDLE;
	m_index = 0;
	m_family = 0;
}

VkResult Queue::Create(uint32_t family, uint32_t index)
{
	VkDevice handle = mDevice->GetHandle();
	vkGetDeviceQueue(handle, family, index, &m_queue);
	assert(m_queue != VK_NULL_HANDLE);
	mResult = VK_SUCCESS;
	m_properties = mDevice->GetPhysicalDevice()->GetQueueFamilyProperties(m_family);
	m_fence = Fence::New(mDevice);
	m_fence->Create();
	return mResult;
}

void Queue::FlushCommandBuffer(CommandBuffer* buffer)
{
	VkCommandBuffer command_buffer = buffer->GetHandle();
	VkSubmitInfo submit_info = Vulkan::Queue::SubmitInfo();
	submit_info.commandBufferCount = 1;
	submit_info.pCommandBuffers = &command_buffer;
	Submit(1, &submit_info);
}

void Queue::Submit(uint32_t count, const VkSubmitInfo* info)
{
	VkFence fence = m_fence->GetHandle();
	mResult = vkQueueSubmit(m_queue, count, info, fence);
	assert(mResult == VK_SUCCESS);
	m_fence->WaitFor();
	m_fence->Reset();
}

void Queue::Submit(const std::vector<VkSubmitInfo>& infos)
{
	Submit(infos.size(), infos.data());
}

void Queue::Submit(const std::vector<VkCommandBuffer>& buffers, const std::vector<VkSemaphore>& semaphores)
{
	VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	VkSubmitInfo submit_info = {};
	submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit_info.pWaitDstStageMask = &wait_stage_mask;
	submit_info.waitSemaphoreCount = semaphores.size();
	submit_info.pWaitSemaphores = semaphores.data();
	submit_info.commandBufferCount = buffers.size();
	submit_info.pCommandBuffers = buffers.data();;
	submit_info.signalSemaphoreCount = 0;
	submit_info.pSignalSemaphores = nullptr;
	Submit(1, &submit_info);
}

void Queue::Present(const VkPresentInfoKHR* info)
{
	mResult = vkQueuePresentKHR(m_queue, info);
	assert(mResult == VK_SUCCESS);
	mResult = vkQueueWaitIdle(m_queue);
	assert(mResult != VK_TIMEOUT);
}

VkDeviceQueueCreateInfo Queue::CreateInfo(void)
{
	VkDeviceQueueCreateInfo device_queue_create_info = {};
	device_queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	device_queue_create_info.pNext = nullptr;
	device_queue_create_info.flags = 0;
	device_queue_create_info.queueCount = 1;
	device_queue_create_info.pQueuePriorities = nullptr;
	device_queue_create_info.queueFamilyIndex = 0;
	return device_queue_create_info;
}

VkSubmitInfo Queue::SubmitInfo(void)
{
	VkSubmitInfo submit_info = {};
	submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit_info.pNext = nullptr;
	submit_info.commandBufferCount = 0;
	submit_info.pCommandBuffers = nullptr;
	submit_info.signalSemaphoreCount = 0;
	submit_info.pSignalSemaphores = nullptr;
	submit_info.waitSemaphoreCount = 0;
	submit_info.pWaitSemaphores = nullptr;
	submit_info.pWaitDstStageMask = nullptr;
	return submit_info;
}

VkPresentInfoKHR Queue::PresentInfo(void)
{
	VkPresentInfoKHR present_info = {};
	present_info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
	present_info.pNext = nullptr;
	present_info.swapchainCount = 0;
	present_info.pSwapchains = nullptr;
	present_info.waitSemaphoreCount = 0;
	present_info.pWaitSemaphores = nullptr;
	present_info.pImageIndices = nullptr;
	present_info.pResults = nullptr;
	return present_info;
}

} /* namespace Vulkan */
