/*
 * VKCommandPool.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKDevice.h"
#include "VKCommandPool.h"
#include "VKCommandList.h"

#include "VulkanPhysicalDevice.h"
#include "VulkanCommandPool.h"
#include "VulkanInline.h"

#include <cassert>

namespace VK
{

CommandPool::CommandPool(Device* device):
		GHI::CommandPool(device)
{
}

CommandPool::~CommandPool(void)
{
	Vulkan::Release(mCommandPool);
}

void CommandPool::Create(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	auto vulkan_device = vk_device->GetVulkanDevice();
	auto vulkan_physical = vk_device->GetVulkanPhysicalDevice();
	uint32_t family = vulkan_physical->GetFamily();
	mCommandPool = Vulkan::CommandPool::New(vulkan_device);
	mCommandPool->Create(family);
}

GHI::CommandList* CommandPool::Allocate(bool level)
{
	assert(mCommandPool != nullptr);
	CommandList* command_list = new CommandList(this);
	command_list->Create(level);
	mCommandLists.push_back(command_list);
	return command_list;
}

} /* namespace VK */
