/*
 * CommandList.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKCommandList.h"
#include "VKCommandPool.h"

#include "VulkanCommandPool.h"

#include <cassert>

namespace VK
{

CommandList::CommandList(CommandPool* pool):
		Render::CommandList(pool)
{
}

CommandList::~CommandList(void)
{
	mCommandBuffer = nullptr;
}

void CommandList::Create(bool primary)
{
	assert(mCommandPool != nullptr);
	VkCommandBufferLevel level =  primary ? VK_COMMAND_BUFFER_LEVEL_PRIMARY : VK_COMMAND_BUFFER_LEVEL_SECONDARY;
	auto command_pool = static_cast<CommandPool*>(mCommandPool);
	auto vk_command_pool = command_pool->GetCommandPoolVK();
	mCommandBuffer = vk_command_pool->Allocate(level);
}

} /* namespace VK */
