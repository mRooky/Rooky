/*
 * VulkanDebug.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: rookyma
 */

#include "VulkanDebug.h"
#include "VulkanInstance.h"
#include "VulkanDefine.h"
#include <cassert>
#include <iostream>

namespace Vulkan
{

Debug::Debug(Instance* instance):
		mInstance(instance)
{
	VkInstance handle = mInstance->GetHandle();

	const char* creater = "vkCreateDebugReportCallbackEXT";
	m_creator = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(handle, creater));
	assert(m_creator != nullptr);

	const char* deleter = "vkDestroyDebugReportCallbackEXT";
	m_deleter = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(vkGetInstanceProcAddr(handle, deleter));
	assert(m_deleter != nullptr);
}

Debug::~Debug(void)
{
	if (m_debug != VK_NULL_HANDLE)
	{
		VkInstance instance = mInstance->GetHandle();
		m_deleter(instance, m_debug, nullptr);
	}
	m_debug = VK_NULL_HANDLE;
	m_creator = nullptr;
	m_deleter = nullptr;
}

void Debug::Create(const VkDebugReportCallbackCreateInfoEXT* info)
{
	assert(m_creator != nullptr);
	VkInstance instance = mInstance->GetHandle();
	mResult = m_creator(instance, info, nullptr, &m_debug);
	VK_RESULT_CHECK(mResult, VK_SUCCESS);
	assert(m_debug != VK_NULL_HANDLE);
}

VKAPI_ATTR VkBool32 Debug::Function(
			VkFlags flags,
			VkDebugReportObjectTypeEXT obj,
			uint64_t src,
			size_t location,
			int32_t code,
			const char* layer,
			const char* msg,
			void* data)
{
	if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
	{
		std::cout << "[VK_ERROR_MESSAGE] ERROR : [" << layer << "] Code " << code << " : " << msg << std::endl;
	}
	else if (flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT)
	{
		std::cout << "[VK_DEBUG_INFORMATION] DEBUG : [" << layer << "] Code " << code << " : " << msg << std::endl;
	}
	else if (flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT)
	{
		std::cout << "[VK_DEBUG_MESSAGE] DEBUG : [" << layer << "] Code " << code << " : " << msg << std::endl;
	}
	else if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
	{
		std::cout << "[VK_WARNING_MESSAGE] WARNING : [" << layer << "] Code " << code << " : " << msg << std::endl;
	}
	else if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT)
	{
		std::cout << "[VK_PERFORMANCE_MESSAGE] PERFORMANCE : [" << layer << "] Code " << code << " : " << msg << std::endl;
	}
	else
	{
		return VK_FALSE;
	}
	return VK_SUCCESS;
}

VkDebugReportCallbackCreateInfoEXT Debug::CreateInfo(void)
{
	VkDebugReportCallbackCreateInfoEXT debug_create_info = {};
	debug_create_info.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
	debug_create_info.pNext = nullptr;
	debug_create_info.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT
			| VK_DEBUG_REPORT_INFORMATION_BIT_EXT
			| VK_DEBUG_REPORT_DEBUG_BIT_EXT
			| VK_DEBUG_REPORT_WARNING_BIT_EXT
			| VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
	debug_create_info.pUserData = nullptr;
	debug_create_info.pfnCallback = static_cast<PFN_vkDebugReportCallbackEXT>(Debug::Function);

	return debug_create_info;
}

} /* namespace Vulkan */
