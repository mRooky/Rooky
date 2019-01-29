/*
 * VulkanSwapChain.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanSwapChain.h"
#include "VulkanDevice.h"
#include "VulkanSurface.h"
#include "VulkanImage.h"
#include "VulkanSemaphore.h"
#include "VulkanFence.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanInline.h"
#include <cassert>

namespace Vulkan
{

SwapChain::SwapChain(Device* device):
		DeviceObject(device)
{
}

SwapChain::~SwapChain(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroySwapchainKHR(device, m_swapchain, nullptr);
	mDevice = nullptr;
	m_surface = VK_NULL_HANDLE;
	m_swapchain = VK_NULL_HANDLE;
	for (auto image : m_images)
	{
		Vulkan::Release(image);
	}
	m_images.clear();
	Vulkan::Release(m_fence);
	Vulkan::Release(m_semaphore);
}

VkResult SwapChain::Create(Surface* surface)
{
	assert(m_swapchain == VK_NULL_HANDLE);
	m_surface = surface;
	const VkSurfaceCapabilitiesKHR& capabilities = surface->GetCapabilities();
	const VkSurfaceFormatKHR& format = surface->GetFormat(0);
	uint32_t family = mDevice->GetPhysicalDevice()->GetFamily();

	VkSwapchainCreateInfoKHR swapchain_create_info = SwapChain::CreateInfo();
	swapchain_create_info.surface = surface->GetHandle();
	swapchain_create_info.minImageCount = 2;
	swapchain_create_info.imageFormat = format.format;
	swapchain_create_info.imageColorSpace = format.colorSpace;
	swapchain_create_info.imageExtent = capabilities.currentExtent;
	swapchain_create_info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	swapchain_create_info.preTransform = surface->GetTransformFlag();
	swapchain_create_info.imageArrayLayers = 1;
	swapchain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	swapchain_create_info.queueFamilyIndexCount = 1;
	swapchain_create_info.pQueueFamilyIndices = &family;
	swapchain_create_info.presentMode = VK_PRESENT_MODE_FIFO_KHR;
	swapchain_create_info.oldSwapchain = VK_NULL_HANDLE;
	swapchain_create_info.clipped = VK_TRUE;
	swapchain_create_info.compositeAlpha = surface->GetCompositeAlphaFlag();

	return Create(&swapchain_create_info);
}

VkResult SwapChain::Create(const VkSwapchainCreateInfoKHR* info)
{
	assert(m_swapchain == VK_NULL_HANDLE);
	mResult = vkCreateSwapchainKHR(mDevice->GetHandle(), info, nullptr, &m_swapchain);
	assert(mResult == VK_SUCCESS);
	m_info = *info;
	CreateImage();
	CreateSynchronization();
	return mResult;
}

void SwapChain::CreateImage(void)
{
	uint32_t count = 0;
	VkDevice devcie = mDevice->GetHandle();
	mResult = vkGetSwapchainImagesKHR(devcie, m_swapchain, &count, nullptr);
	assert(mResult == VK_SUCCESS && count == 2);
	if (count == 2)
	{
		const VkSurfaceCapabilitiesKHR& capabilities = m_surface->GetCapabilities();
		std::vector<VkImage> images;
		images.resize(count);
		mResult = vkGetSwapchainImagesKHR(devcie, m_swapchain, &count, images.data());
		assert(mResult == VK_SUCCESS);
		const VkSurfaceFormatKHR& format = m_surface->GetFormat(0);
		m_images.reserve(2);

		uint32_t family = mDevice->GetPhysicalDevice()->GetFamily();
		VkImageCreateInfo image_create_info = Vulkan::Image::CreateInfo();
		image_create_info.format = format.format;
		image_create_info.extent.width = capabilities.currentExtent.width;
		image_create_info.extent.height = capabilities.currentExtent.height;
		image_create_info.extent.depth = 1;
		image_create_info.mipLevels = 1;
		image_create_info.arrayLayers = 1;
		image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		image_create_info.queueFamilyIndexCount = 1;
		image_create_info.pQueueFamilyIndices = &family;

		for (uint32_t index = 0; index < count; ++index)
		{
			SwapChainImage* image = SwapChainImage::New(mDevice);
			VkImage handle = images.at(index);
			image->Create(handle, &image_create_info);
			image->CreateView(VK_IMAGE_VIEW_TYPE_2D);
			m_images.push_back(image);
		}
	}
}

void SwapChain::CreateSynchronization(void)
{
	m_semaphore = Semaphore::New(mDevice);
	mResult = m_semaphore->Create();
	assert(mResult == VK_SUCCESS);

	m_fence = Fence::New(mDevice);
	mResult = m_fence->Create();
	assert(mResult == VK_SUCCESS);
}

uint32_t SwapChain::AcquireNextImage(void)
{
	VkDevice device = mDevice->GetHandle();
	VkSemaphore semaphore = m_semaphore->GetHandle();
	VkFence fence = m_fence->GetHandle();
	mResult = vkAcquireNextImageKHR(device, m_swapchain, UINT32_MAX, semaphore, fence, &m_index);
	assert(mResult == VK_SUCCESS);
	m_fence->WaitFor();
	m_fence->Reset();
	return m_index;
}

VkSwapchainCreateInfoKHR SwapChain::CreateInfo(void)
{
	VkSwapchainCreateInfoKHR swap_chain_create_info = {};
	swap_chain_create_info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	swap_chain_create_info.pNext = nullptr;
	swap_chain_create_info.flags = 0;
	swap_chain_create_info.surface = VK_NULL_HANDLE;
	swap_chain_create_info.minImageCount = 0;
	swap_chain_create_info.imageFormat = VK_FORMAT_UNDEFINED;
	swap_chain_create_info.imageColorSpace = VK_COLOR_SPACE_MAX_ENUM_KHR;
	swap_chain_create_info.imageExtent.width = 0;
	swap_chain_create_info.imageExtent.height = 0;
	swap_chain_create_info.imageArrayLayers = 1;
	swap_chain_create_info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	swap_chain_create_info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	swap_chain_create_info.queueFamilyIndexCount = 0;
	swap_chain_create_info.pQueueFamilyIndices = nullptr;
	swap_chain_create_info.preTransform = VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR;
	swap_chain_create_info.compositeAlpha = VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR;
	swap_chain_create_info.presentMode = VK_PRESENT_MODE_MAX_ENUM_KHR;
	swap_chain_create_info.clipped = VK_TRUE;
	swap_chain_create_info.oldSwapchain = VK_NULL_HANDLE;
	return swap_chain_create_info;
}

} /* namespace Vulkan */
