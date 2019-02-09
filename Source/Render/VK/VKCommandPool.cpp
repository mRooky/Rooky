/*
 * VKCommandPool.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKCommandPool.h"
#include "VKContext.h"
#include "VKCommandList.h"

#include "VulkanPhysicalDevice.h"
#include "VulkanCommandPool.h"
#include "VulkanInline.h"

namespace VK
{

CommandPool::CommandPool(Context* context):
		Render::CommandPool(context)
{
}

CommandPool::~CommandPool(void)
{
	Vulkan::Release(mCommandPool);
}

void CommandPool::Initialize(void)
{
	auto context = static_cast<Context*>(mContext);
	auto device = context->GetDeviceVK();
	auto physical = context->GetPhysicalDeviceVK();
	uint32_t family = physical->GetFamily();
	mCommandPool = Vulkan::CommandPool::New(device);
	mCommandPool->Create(family);
}

Render::CommandList* CommandPool::Allocate(bool level)
{
	CommandList* command_list = new CommandList(this);
	command_list->Create(level);
	mCommandLists.push_back(command_list);
	return command_list;
}

} /* namespace VK */
