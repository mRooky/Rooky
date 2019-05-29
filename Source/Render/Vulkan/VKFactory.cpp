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
#include "VKDevice.h"
#include "VKSampler.h"
#include "VKPipeline.h"
#include "VKPipelineState.h"
#include "VKPipelineLayout.h"

#include "../../Platform/Vulkan/VulkanCommandPool.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanPhysicalDevice.h"

#include <cassert>

namespace VK
{

Factory::Factory(Device* device):
		GHI::Factory(device)
{
	mPool = new Pool(static_cast<Device&>(*mDevice));
}

Factory::~Factory(void)
{
	delete mPool;
	mPool = nullptr;
}

GHI::RenderPass* Factory::CreateRenderPass(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new RenderPass(vk_device);
}

GHI::Image* Factory::CreateImage(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Image(vk_device);
}

GHI::Buffer* Factory::CreateBuffer(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Buffer(vk_device);
}

GHI::Shader* Factory::CreateShader(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Shader(vk_device);
}

GHI::SwapChain* Factory::CreateSwapChain(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new SwapChain(vk_device);
}

GHI::CommandPool* Factory::CreateCommandPool(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new CommandPool(vk_device);
}

GHI::Sampler* Factory::CreateSampler(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Sampler(vk_device);
}

GHI::Pipeline* Factory::CreatePipeline(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new Pipeline(vk_device);
}

GHI::BindingSet* Factory::CreateBindingSet(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new BindingSet(vk_device);
}

GHI::PipelineLayout* Factory::CreatePipelineLayout(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	return new PipelineLayout(vk_device);
}

} /* namespace VK */
