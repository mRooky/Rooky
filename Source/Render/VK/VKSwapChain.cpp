/*
 * VKSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKSwapChain.h"
#include "VKImage.h"
#include "VKDevice.h"

#include "VulkanInline.h"
#include "VulkanSurface.h"
#include "VulkanSwapChain.h"
#include "VulkanDevice.h"
#include "VulkanImage.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"

#ifdef VK_USE_PLATFORM_XCB_KHR
#include "Platform/XCB/XCBWindow.h"
#endif

#include <cassert>

namespace VK
{

SwapChain::SwapChain(Device* device):
		Render::SwapChain(device)
{
}

SwapChain::~SwapChain(void)
{
	Vulkan::Release(mSurface);
	Vulkan::Release(mSwapChain);
}

void SwapChain::Create(Platform::Window* window)
{
	auto vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	mSurface = Vulkan::Surface::New(vulkan_device->GetPhysicalDevice());

#ifdef VK_USE_PLATFORM_XCB_KHR
	auto xcb_window = static_cast<XCB::Window*>(window);
	mSurface->Create(xcb_window->GetConnection(), xcb_window->GetWindow());
#endif

	mSwapChain = Vulkan::SwapChain::New(vulkan_device);
	mSwapChain->Create(mSurface);

	GetSwapChainRenderBuffer();
}

void SwapChain::SwapBuffer(uint32_t index)
{
	assert(mSwapChain != nullptr);

	auto device = mSwapChain->GetDevice();
	auto physical = device->GetPhysicalDevice();
	uint32_t family = physical->GetFamily();
	auto queue = device->GetQueue(family, index);

	uint32_t next = mSwapChain->AcquireNextImage();
	auto handle = mSwapChain->GetHandle();
	VkPresentInfoKHR present_info = Vulkan::Queue::PresentInfo();
	present_info.swapchainCount = 1;
	present_info.pSwapchains = &handle;
	present_info.pImageIndices = &next;
	queue->Present(&present_info);
}

uint32_t SwapChain::AcquireNextImage(void)
{
	assert(mSwapChain != nullptr);
	uint32_t index = mSwapChain->AcquireNextImage();
	return index;
}

void SwapChain::GetSwapChainRenderBuffer(void)
{
	assert(mSwapChain != nullptr);
	auto vk_device = static_cast<Device*>(mDevice);
	const size_t count = 2;
	for (size_t index = 0; index < count; ++index)
	{
		SwapChainImage* image = new SwapChainImage(vk_device);
		auto vk_image = mSwapChain->GetImage(index);
		image->Create(vk_image);
		image->mSwapChain = this;
		mRenderBuffers.push_back(image);
	}
}

} /* namespace VK */
