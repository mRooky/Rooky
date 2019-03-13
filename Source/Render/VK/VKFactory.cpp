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
#include "VKResourceHeap.h"

#include "VulkanCommandPool.h"
#include "VulkanInline.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"

namespace VK
{

Factory::Factory(Context* context):
		Render::Factory(context)
{
	CreateDefaultPool();
	mResourceHeap = new ResourceHeap(context);
}

Factory::~Factory(void)
{
	delete mResourceHeap;
	mResourceHeap = nullptr;
	Vulkan::Release(mCommandPool);
}

void Factory::CreateDefaultPool(void)
{
	auto device = StaticCast(mContext)->GetVulkanDevice();
	uint32_t family = device->GetPhysicalDevice()->GetFamily();
	mCommandPool = Vulkan::CommandPool::New(device);
	mCommandPool->Create(family);
	mCommandPool->Allocate(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}

Render::Pass* Factory::CreatePass(void)
{
	Context* context = StaticCast(mContext);
	return new RenderPass(context);
}

Render::Queue* Factory::CreateQueue(void)
{
	Context* context = StaticCast(mContext);
	return new Queue(context);
}

Render::Image* Factory::CreateImage(void)
{
	Context* context = StaticCast(mContext);
	return new Image(context);
}

Render::Buffer* Factory::CreateBuffer(void)
{
	Context* context = StaticCast(mContext);
	return new Buffer(context);
}

Render::Shader* Factory::CreateShader(void)
{
	Context* context = StaticCast(mContext);
	return new Shader(context);
}

Render::SwapChain* Factory::CreateSwapChain(void)
{
	Context* context = StaticCast(mContext);
	return new SwapChain(context);
}

Render::CommandPool* Factory::CreateCommandPool(void)
{
	Context* context = StaticCast(mContext);
	return new CommandPool(context);
}

Render::Declaration* Factory::CreateDeclaration(void)
{
	return new Declaration;
}

} /* namespace VK */
