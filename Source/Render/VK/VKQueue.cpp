/*
 * VKQueue.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKQueue.h"
#include "VKContext.h"
#include "VKCommandList.h"

#include "VulkanCommandBuffer.h"
#include "VulkanSemaphore.h"
#include "VulkanQueue.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDevice.h"

#include <cassert>

namespace VK
{

Queue::Queue(Context* context):
		Render::Queue(context)
{
}

Queue::~Queue(void)
{
	mQueue = nullptr;
}

void Queue::Create(uint32_t mIndex)
{
	auto context = StaticCast(mContext);
	auto device = context->GetDeviceVK();
	auto physical = context->GetPhysicalDeviceVK();
	uint32_t family = physical->GetFamily();
	mQueue = device->GetQueue(family, mIndex);
}

void Queue::Submit(Render::CommandList* command)
{
	assert(mQueue != nullptr);
	auto command_list = StaticCast(command);
	auto command_buffer = command_list->GetCommandBufferVK();
	auto vk_command = command_buffer->GetHandle();
	auto vk_semaphore = command_buffer->GetSemaphore()->GetHandle();
	VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;

	VkSubmitInfo submit_info = Vulkan::Queue::SubmitInfo();
	submit_info.commandBufferCount = 1;
	submit_info.pCommandBuffers = &vk_command;
	submit_info.waitSemaphoreCount = 1;
	submit_info.pWaitSemaphores = &vk_semaphore;
	submit_info.pWaitDstStageMask = &wait_stage_mask;

	mQueue->Submit(1, &submit_info);
}

} /* namespace VK */
