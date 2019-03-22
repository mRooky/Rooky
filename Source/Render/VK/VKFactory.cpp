/*
 * VKFactory.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "VKFactory.h"
#include "VKContext.h"
#include "VKImage.h"
#include "VKBuffer.h"
#include "VKSwapChain.h"
#include "VKRenderPass.h"
#include "VKCommandPool.h"
#include "VKQueue.h"
#include "VKShader.h"
#include "VKDeclaration.h"
#include "VKStaging.h"
#include "VKBindingState.h"
#include "VKBindingLayout.h"

#include "VulkanCommandPool.h"
#include "VulkanInline.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"

#include <cassert>

namespace VK
{

Factory::Factory(Context* context):
		Render::Factory(context)
{
	CreateDefaultPool();
	mStaging = new Staging(context);
}

Factory::~Factory(void)
{
	delete mStaging;
	mStaging = nullptr;
	Vulkan::Release(mCommandPool);
}

void Factory::CreateDefaultPool(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	auto device = vk_context->GetVulkanDevice();
	uint32_t family = device->GetPhysicalDevice()->GetFamily();
	mCommandPool = Vulkan::CommandPool::New(device);
	mCommandPool->Create(family);
	mCommandPool->Allocate(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}

Render::Pass* Factory::CreatePass(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new RenderPass(vk_context);
}

Render::Queue* Factory::CreateQueue(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new Queue(vk_context);
}

Render::Image* Factory::CreateImage(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new Image(vk_context);
}

Render::Buffer* Factory::CreateBuffer(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new Buffer(vk_context);
}

Render::Shader* Factory::CreateShader(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new Shader(vk_context);
}

Render::SwapChain* Factory::CreateSwapChain(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new SwapChain(vk_context);
}

Render::CommandPool* Factory::CreateCommandPool(void)
{
	auto vk_context = static_cast<Context*>(mContext);
	return new CommandPool(vk_context);
}

Render::Declaration* Factory::CreateDeclaration(void)
{
	return new Declaration;
}

Render::BindingState* Factory::CreateBindingState(void)
{
	assert(false);
	return nullptr;
}

Render::BindingLayout* Factory::CreateBindingLayout(void)
{
	assert(false);
	return nullptr;
}

} /* namespace VK */
