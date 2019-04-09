/*
 * DirectContext.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: rookyma
 */

#include "DirectContext.h"
#include "VulkanInstance.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDevice.h"
#include "VulkanInline.h"
#include <cassert>

namespace Direct
{
Context* Context::g_context = nullptr;
Context::Context(Vulkan::Device* device)
{
	m_internal = (device == nullptr);
	if (m_internal)
	{
		m_instance = Vulkan::Instance::New();
		m_physicalDevice = Vulkan::PhysicalDevice::New(m_instance);
		m_device = Vulkan::Device::New(m_physicalDevice);
		assert(false);
	}
	else
	{
		m_device = device;
		m_physicalDevice = device->GetPhysicalDevice();
		m_instance = m_physicalDevice->GetInstance();
	}
	assert(g_context == nullptr);
	g_context = this;
}

Context::~Context(void)
{
	assert(g_context != nullptr);
	g_context = nullptr;
	if (m_internal)
	{
		Vulkan::Release(m_device);
		Vulkan::Release(m_physicalDevice);
		Vulkan::Release(m_instance);
		m_internal = false;
	}
}

} /* namespace Direct */
