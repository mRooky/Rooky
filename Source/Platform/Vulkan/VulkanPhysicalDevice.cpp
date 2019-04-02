/*
 * VulkanPhysicalDevice.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanPhysicalDevice.h"
#include "VulkanInstance.h"
#include <cassert>
#include <array>

namespace Vulkan
{

PhysicalDevice::PhysicalDevice(Instance* instance):
		m_instance(instance)
{
	assert(m_instance != nullptr);
}

PhysicalDevice::~PhysicalDevice(void)
{
	m_instance = nullptr;
	m_flags = 0;
	m_physicalDevice = VK_NULL_HANDLE;
}

VkResult PhysicalDevice::Create(VkQueueFlags flags)
{
	assert(VK_SUCCESS == m_instance->GetResult());
	m_flags = flags;
	VkInstance handle = m_instance->GetHandle();
	uint32_t count = 0;
	mResult = vkEnumeratePhysicalDevices(handle, &count, nullptr);
	assert(mResult == VK_SUCCESS);
	if (mResult == VK_SUCCESS && count != 0)
	{
		std::vector<VkPhysicalDevice> physical_devices;
		physical_devices.resize(count);
		mResult = vkEnumeratePhysicalDevices(handle, &count, physical_devices.data());
		assert(mResult == VK_SUCCESS);
		for (VkPhysicalDevice physical : physical_devices)
		{
			uint32_t count = 0;
			vkGetPhysicalDeviceQueueFamilyProperties(physical, &count, NULL);
			assert(count > 0);
			m_familyProperties.resize(count);
			vkGetPhysicalDeviceQueueFamilyProperties(physical, &count, m_familyProperties.data());
			for (uint32_t index = 0; index < count; ++index)
			{
				auto flags = m_familyProperties.at(index).queueFlags;
				if ((m_flags & flags) == m_flags)
				{
					m_family = index;
					m_physicalDevice = physical;
					InitializeProperties();
					return mResult;
				}
			}
			assert(false);
		}
	}
	return VK_INCOMPLETE;
}

void PhysicalDevice::InitializeProperties(void)
{
	vkGetPhysicalDeviceFeatures(m_physicalDevice, &m_features);
	vkGetPhysicalDeviceProperties(m_physicalDevice, &m_properties);
	vkGetPhysicalDeviceMemoryProperties(m_physicalDevice, &m_memoryProperties);
}

uint32_t PhysicalDevice::GetMemoryTypeIndex(uint32_t bits, VkMemoryPropertyFlags flag) const
{
	for (uint32_t index = 0; index < m_memoryProperties.memoryTypeCount; ++index)
	{
		if (bits & (1 << index))
		{
			if((m_memoryProperties.memoryTypes[index].propertyFlags & flag) == flag)
			{
				return index;
			}
		}
	}
	assert(false);
	return ~0u;
}

VkFormatProperties PhysicalDevice::GetFormatProperties(VkFormat format) const
{
	assert(m_physicalDevice != VK_NULL_HANDLE);
	VkFormatProperties properties = {};
	vkGetPhysicalDeviceFormatProperties(m_physicalDevice, format, &properties);
	return properties;
}

VkFormat PhysicalDevice::GetDepthStencilFormat(void) const
{
	const static std::array<VkFormat, 5> depth_formats =
	{
		VK_FORMAT_D32_SFLOAT_S8_UINT,
		VK_FORMAT_D32_SFLOAT,
		VK_FORMAT_D24_UNORM_S8_UINT,
		VK_FORMAT_D16_UNORM_S8_UINT,
		VK_FORMAT_D16_UNORM
	};

	for (size_t i = 0; i < 5; ++i)
	{
		auto format = depth_formats.at(i);
		VkFormatProperties properties = GetFormatProperties(format);
		VkFormatFeatureFlags tiling = properties.optimalTilingFeatures;
		if (tiling & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
		{
			return format;
		}
	}
	assert(false);
	return VK_FORMAT_UNDEFINED;
}

VkImageTiling PhysicalDevice::GetFormatTiling(VkFormat format, VkFormatFeatureFlags feature) const
{
	VkImageTiling tiling = VK_IMAGE_TILING_LINEAR;
	VkFormatProperties properties = GetFormatProperties(format);
	if (properties.optimalTilingFeatures & feature)
	{
		tiling = VK_IMAGE_TILING_OPTIMAL;
	}

	if (properties.linearTilingFeatures)
	{
		if (tiling == VK_IMAGE_TILING_LINEAR)
		{
			assert(properties.linearTilingFeatures & feature);
		}
	}
	return tiling;
}

} /* namespace Vulkan */
