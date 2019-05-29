/*
 * VKContext.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKDevice.h"
#include "VKBuffer.h"
#include "VKImage.h"
#include "VKFormat.h"
#include "VKInline.h"
#include "VKFactory.h"
#include "VKQueue.h"

#include "../../Platform/Vulkan/VulkanVendor.h"
#include "../../Platform/Vulkan/VulkanInstance.h"
#include "../../Platform/Vulkan/VulkanDebug.h"
#include "../../Platform/Vulkan/VulkanPhysicalDevice.h"
#include "../../Platform/Vulkan/VulkanQueue.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanCommon.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanCommandPool.h"

#include <cassert>

namespace VK
{

Device::Device(void)
{
}

Device::~Device(void)
{
	delete mFactory;
	mFactory = nullptr;
	Vulkan::Release(m_device);
	Vulkan::Release(m_physical);
	Vulkan::Release(m_instance);
	Vulkan::Release(m_vendor);
}

void Device::Create(void)
{
	CreateVendor();
	CreateInstance();
	CreatePhysical();
	CreateDevice();
	CreateQueue(1);
	mFactory = new Factory(this);
}

GHI::Format Device::GetBestDepthStencilFormat(void)
{
	VkFormat vk_format = m_physical->GetDepthStencilFormat();
	GHI::Format format = ConvertFormat(vk_format);
	return format;
}

void Device::CreateVendor(void)
{
	m_vendor = Vulkan::Vendor::New();
	m_vendor->Init();
}

void Device::CreateInstance(bool debug)
{
	m_instance = Vulkan::Instance::New();

	m_instance->EnableExtension(VK_KHR_SURFACE_EXTENSION_NAME);

#ifdef VK_USE_PLATFORM_XCB_KHR
	m_instance->EnableExtension(VK_KHR_XCB_SURFACE_EXTENSION_NAME);
#else
	assert(false);
#endif

	if (debug == true)
	{
		const char* standard_validation = "VK_LAYER_LUNARG_standard_validation";
		bool exist = m_vendor->DoesLayerExist(standard_validation);
		if (exist == true)
		{
			m_instance->EnableLayer(standard_validation);
		}

		exist = m_vendor->DoesExtensionExist(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		if (exist == true)
		{
			m_instance->EnableExtension(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		}
	}

	m_instance->Create("Vulkan", debug);
}

void Device::CreatePhysical(void)
{
	VkQueueFlags flags = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT;
	m_physical = Vulkan::PhysicalDevice::New(m_instance);
	m_physical->Create(flags);
//	Vulkan::DumpLimits(m_physical);
//	Vulkan::DumpFormatsProperties(m_physical);
}

void Device::CreateDevice(void)
{
	m_device = Vulkan::Device::New(m_physical);

	const float priority = 0.0f;
	uint32_t family = m_physical->GetFamily();

	VkDeviceQueueCreateInfo queue_create_info = Vulkan::Queue::CreateInfo();
	queue_create_info.queueFamilyIndex = family;
	queue_create_info.queueCount = 1;
	queue_create_info.pQueuePriorities = &priority;

	std::vector<const char*> device_extensions;
	device_extensions.reserve(1);
	device_extensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

	VkPhysicalDeviceFeatures features = m_physical->GetFeatures();

	VkDeviceCreateInfo device_create_info = Vulkan::Device::CreateInfo();
	device_create_info.queueCreateInfoCount = 1;
	device_create_info.pQueueCreateInfos = &queue_create_info;
	device_create_info.enabledExtensionCount = device_extensions.size();
	device_create_info.ppEnabledExtensionNames = device_extensions.data();
	device_create_info.pEnabledFeatures = &features;

	m_device->Create(&device_create_info);
}

void Device::CreateQueue(size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		Queue* queue = new Queue(this);
		mQueues.push_back(queue);
		queue->Create(i);
	}
}

} /* namespace VK */
