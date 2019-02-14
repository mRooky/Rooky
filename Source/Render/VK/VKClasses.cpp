/*
 * VKClasses.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "VKContext.h"
#include "VKImage.h"
#include "VKBuffer.h"
#include "VKSwapChain.h"
#include "VKRenderPass.h"
#include "VKCommandPool.h"
#include "VKQueue.h"

namespace VK
{

Render::Pass* Context::CreatePass(void)
{
	return new RenderPass(this);
}

Render::Image* Context::CreateImage(void)
{
	return new Image(this);
}

Render::Queue* Context::CreateQueue(void)
{
	return new Queue(this);
}

Render::Buffer* Context::CreateBuffer(void)
{
	return new Buffer(this);
}

Render::SwapChain* Context::CreateSwapChain(void)
{
	return new SwapChain(this);
}

Render::CommandPool* Context::CreateCommandPool(void)
{
	return new CommandPool(this);
}

}
