/*
 * VKSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKSwapChain.h"
#include "VKContext.h"
#include "VKImage.h"

#include "VulkanInline.h"
#include "VulkanSurface.h"
#include "VulkanSwapChain.h"
#include "VulkanDevice.h"
#include "VulkanImage.h"

#ifdef VK_USE_PLATFORM_XCB_KHR
#include "Platform/XCB/XCBWindow.h"
#endif

namespace VK
{

SwapChain::SwapChain(Context* context):
		Render::SwapChain(context)
{
}

SwapChain::~SwapChain(void)
{
	Vulkan::Release(mSurface);
	Vulkan::Release(mSwapChain);
}

void SwapChain::Create(Platform::Window* window)
{
	auto context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mSurface = Vulkan::Surface::New(device->GetPhysicalDevice());

#ifdef VK_USE_PLATFORM_XCB_KHR
	auto xcb_window = static_cast<XCB::Window*>(window);
	mSurface->Create(xcb_window->GetConnection(), xcb_window->GetWindow());
#endif

	mSwapChain = Vulkan::SwapChain::New(device);
	mSwapChain->Create(mSurface);

	GetSwapChainRenderBuffer();
}

void SwapChain::GetSwapChainRenderBuffer(void)
{
	assert(mSwapChain != nullptr);
	auto context = static_cast<Context*>(mContext);
	const size_t count = 2;
	for (size_t index = 0; index < count; ++index)
	{
		SwapChainImage* image = new SwapChainImage(context);
		auto vk_image = mSwapChain->GetImage(index);
		image->Create(vk_image);
		mRenderBuffers.push_back(image);
	}
}

} /* namespace VK */
