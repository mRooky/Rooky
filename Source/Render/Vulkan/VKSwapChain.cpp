/*
 * VKSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKSwapChain.h"
#include "VKImage.h"
#include "VKDevice.h"

#ifdef VK_USE_PLATFORM_XCB_KHR
#include "Platform/XCB/XCBWindow.h"
#endif

#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanSurface.h"
#include "../../Platform/Vulkan/VulkanSwapChain.h"
#include "../../Platform/Vulkan/VulkanSemaphore.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanImage.h"
#include "../../Platform/Vulkan/VulkanPhysicalDevice.h"
#include "../../Platform/Vulkan/VulkanQueue.h"

#include <cassert>

namespace VK
{

SwapChain::SwapChain(Device* device):
		GHI::SwapChain(device)
{
}

SwapChain::~SwapChain(void)
{
	Vulkan::Release(mSwapChain);
	Vulkan::Release(mSurface);
}

void SwapChain::Create(Platform::Window* window)
{
	Device* vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	Vulkan::PhysicalDevice* gpu = vulkan_device->GetPhysicalDevice();
	mSurface = Vulkan::Surface::New(gpu);

#ifdef VK_USE_PLATFORM_XCB_KHR
	auto xcb_window = static_cast<XCB::Window*>(window);
	auto connection = xcb_window->GetConnection();
	auto handle = xcb_window->GetWindow();
	mSurface->Create(connection, handle);
#endif

	const auto& capabilities = mSurface->GetCapabilities();
	const auto& current_extent = capabilities.currentExtent;
	mExtent.width = static_cast<int32_t>(current_extent.width);
	mExtent.height = static_cast<int32_t>(current_extent.height);

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
	VkSwapchainKHR swap_chain = mSwapChain->GetHandle();
	Vulkan::Semaphore* semaphore = mSwapChain->GetSemaphore();
	VkSemaphore chain_semaphore = semaphore->GetHandle();
	VkPresentInfoKHR present_info = Vulkan::Queue::PresentInfo();
	present_info.waitSemaphoreCount = 1;
	present_info.pWaitSemaphores = &chain_semaphore;
	present_info.swapchainCount = 1;
	present_info.pSwapchains = &swap_chain;
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
		mRenderBuffers.push_back(image);
	}
	mFormat = mRenderBuffers.at(0)->GetLayout().GetFormat();
}

} /* namespace VK */
