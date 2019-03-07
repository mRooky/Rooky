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

namespace VK
{

Factory::Factory(Context* context):
		Render::Factory(context)
{
}

Factory::~Factory(void)
{
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

} /* namespace VK */
