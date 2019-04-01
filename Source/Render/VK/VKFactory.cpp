/*
 * VKFactory.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "VKFactory.h"
#include "VKImage.h"
#include "VKBuffer.h"
#include "VKSwapChain.h"
#include "VKRenderPass.h"
#include "VKCommandPool.h"
#include "VKQueue.h"
#include "VKShader.h"
#include "VKPool.h"
#include "VKBindingSet.h"
#include "VKVertexLayout.h"
#include "VKDevice.h"
#include "VKSampler.h"
#include "VKPipeline.h"
#include "VKPipelineState.h"
#include "VKPipelineLayout.h"

#include "VulkanCommandPool.h"
#include "VulkanInline.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"

#include <cassert>

namespace VK
{

Factory::Factory(Device* device):
		Render::Factory(device)
{
	mPool = new Pool(static_cast<Device&>(*mDevice));
}

Factory::~Factory(void)
{
	delete mPool;
	mPool = nullptr;
}

Render::Pass* Factory::CreatePass(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new RenderPass(vk_device);
}

Render::Queue* Factory::CreateQueue(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Queue(vk_device);
}

Render::Image* Factory::CreateImage(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Image(vk_device);
}

Render::Buffer* Factory::CreateBuffer(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Buffer(vk_device);
}

Render::Shader* Factory::CreateShader(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Shader(vk_device);
}

Render::SwapChain* Factory::CreateSwapChain(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new SwapChain(vk_device);
}

Render::CommandPool* Factory::CreateCommandPool(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new CommandPool(vk_device);
}

Render::VertexLayout* Factory::CreateVertexLayout(void)
{
	return new VertexLayout;
}

Render::Sampler* Factory::CreateSampler(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Sampler(vk_device);
}

Render::Pipeline* Factory::CreatePipeline(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Pipeline(vk_device);
}

Render::BindingSet* Factory::CreateBindingSet(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new BindingSet(vk_device);
}

Render::PipelineLayout* Factory::CreatePipelineLayout(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new PipelineLayout(vk_device);
}

} /* namespace VK */
