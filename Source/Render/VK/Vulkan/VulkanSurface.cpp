/*
 * VulkanSurface.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanSurface.h"
#include "VulkanInstance.h"
#include "VulkanPhysicalDevice.h"
#include <cassert>

namespace Vulkan
{

Surface::Surface(PhysicalDevice* physical):
		m_physicalDevice(physical)
{
}

Surface::~Surface(void)
{
	Instance* instance = m_physicalDevice->GetInstance();
	vkDestroySurfaceKHR(instance->GetHandle(), m_surface, nullptr);
	m_physicalDevice = nullptr;
	m_surface = VK_NULL_HANDLE;
}

VkResult Surface::Create(const VkXcbSurfaceCreateInfoKHR* info)
{
	Instance* instance = m_physicalDevice->GetInstance();
	mResult = vkCreateXcbSurfaceKHR(instance->GetHandle(), info, nullptr, &m_surface);
	assert(mResult == VK_SUCCESS);
	mResult = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physicalDevice->GetHandle(), m_surface, &m_capabilities);
	assert(mResult == VK_SUCCESS);
	uint32_t count = 0;
	mResult = vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice->GetHandle(), m_surface, &count, NULL);
	assert(mResult == VK_SUCCESS && count > 0);
	if (count > 0)
	{
		m_formats.resize(count);
		mResult = vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice->GetHandle(), m_surface, &count, m_formats.data());
		assert(mResult == VK_SUCCESS);
	}

	VkBool32 support = VK_FALSE;
	uint32_t family = m_physicalDevice->GetFamily();
	vkGetPhysicalDeviceSurfaceSupportKHR(m_physicalDevice->GetHandle(), family, m_surface, &support);
	assert(support == VK_TRUE);

	m_connection = info->connection;
	m_window = info->window;
	return mResult;
}

VkResult Surface::Create(xcb_connection_t* connection, xcb_window_t window)
{
	VkXcbSurfaceCreateInfoKHR surface_create_info = Vulkan::Surface::CreateInfo();
	surface_create_info.connection = connection;
	surface_create_info.window = window;
	return Create(&surface_create_info);
}

VkCompositeAlphaFlagBitsKHR Surface::GetCompositeAlphaFlag(void) const
{
	std::vector<VkCompositeAlphaFlagBitsKHR> composite_alpha_flags;
	composite_alpha_flags.push_back(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR);
	composite_alpha_flags.push_back(VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR);
	composite_alpha_flags.push_back(VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR);
	composite_alpha_flags.push_back(VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR);
	for (auto alpha_flag : composite_alpha_flags)
	{
		if (m_capabilities.supportedCompositeAlpha & alpha_flag)
		{
			return alpha_flag;
		}
	}
	assert(false);
	return VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR;
}

VkSurfaceTransformFlagBitsKHR Surface::GetTransformFlag(void) const
{
	if(m_capabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
	{
		return VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	}
	return m_capabilities.currentTransform;;
}

VkPresentModeKHR Surface::GetPresentMode(bool vsync) const
{
	uint32_t count = 0;
	VkPhysicalDevice physical = m_physicalDevice->GetHandle();
	VkResult result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical, m_surface, &count, nullptr);
	assert(result == VK_SUCCESS && count > 0);
	std::vector<VkPresentModeKHR> present_modes(count);
	result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical, m_surface, &count, present_modes.data());

	VkPresentModeKHR present_mode = VK_PRESENT_MODE_FIFO_KHR;
	if (!vsync)
	{
		for (size_t i = 0; i < count; i++)
		{
			VkPresentModeKHR current_node = present_modes.at(i);
			if (current_node == VK_PRESENT_MODE_MAILBOX_KHR)
			{
				present_mode = VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}
			if (present_mode != VK_PRESENT_MODE_MAILBOX_KHR && current_node == VK_PRESENT_MODE_IMMEDIATE_KHR)
			{
				present_mode = VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
		}
	}
	return present_mode;
}

VkXcbSurfaceCreateInfoKHR Surface::CreateInfo(void)
{
	VkXcbSurfaceCreateInfoKHR surface_create_info = {};
	surface_create_info.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
	surface_create_info.pNext = nullptr;
	surface_create_info.flags = 0;
	surface_create_info.connection = nullptr;
	surface_create_info.window = 0;
	return surface_create_info;
}

} /* namespace Vulkan */
