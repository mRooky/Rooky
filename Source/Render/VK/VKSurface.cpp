/*
 * VKSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKSurface.h"
#include "VKContext.h"

#include "VulkanInline.h"
#include "VulkanSurface.h"
#include "VulkanSwapChain.h"
#include "VulkanDevice.h"

#ifdef VK_USE_PLATFORM_XCB_KHR
#include "Platform/XCB/XCBWindow.h"
#endif

namespace VK
{

Surface::Surface(Context* context):
		Render::Surface(context)
{
}

Surface::~Surface(void)
{
	Vulkan::Release(mSurface);
	Vulkan::Release(mSwapChain);
}

void Surface::Initialize(Platform::Window* window)
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
}

} /* namespace VK */
