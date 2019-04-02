/*
 * VulkanInstance.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanInstance.h"
#include "VulkanDefine.h"
#include "VulkanDebug.h"
#include "VulkanInline.h"

namespace Vulkan
{

Instance::Instance(void)
{
	m_debugReport = Vulkan::Debug::CreateInfo();
}

Instance::~Instance(void)
{
	Release(m_debug);
	vkDestroyInstance(m_instance, nullptr);
}

VkResult Instance::Create(const VkInstanceCreateInfo* info)
{
	mResult = vkCreateInstance(info, nullptr, &m_instance);
	VK_RESULT_CHECK(mResult, VK_SUCCESS);
	return mResult;
}

VkResult Instance::Create(const char* name, bool debug)
{
	VkApplicationInfo application_info = Instance::ApplicationInfo();
	application_info.pApplicationName = name;
	application_info.pEngineName = name;

	VkInstanceCreateInfo instance_create_info = Vulkan::Instance::CreateInfo();

	instance_create_info.pNext = debug ? &m_debugReport : nullptr;

	auto layers = GetEnabledLayers();
	auto extensions = GetEnabledExtensions();

	instance_create_info.pApplicationInfo = &application_info;
	instance_create_info.enabledLayerCount = layers.size();
	instance_create_info.ppEnabledLayerNames = layers.data();
	instance_create_info.enabledExtensionCount = extensions.size();
	instance_create_info.ppEnabledExtensionNames = extensions.data();

	VkResult result = Create(&instance_create_info);

	CreateDebugReport(debug);

	return result;
}

void Instance::EnableLayer(const char* layer)
{
	std::string name = layer;
	auto iterator = std::find(m_layers.begin(), m_layers.end(), name);
	if (iterator == m_layers.end())
	{
		m_layers.push_back(name);
	}
}

void Instance::EnableExtension(const char* extension)
{
	std::string name = extension;
	auto iterator = std::find(m_extensions.begin(), m_extensions.end(), name);
	if (iterator == m_extensions.end())
	{
		m_extensions.push_back(name);
	}
}

void Instance::CreateDebugReport(bool debug)
{
	if (debug == true)
	{
		m_debug = Vulkan::Debug::New(this);
		m_debug->Create(&m_debugReport);
	}
}

std::vector<const char*> Instance::GetEnabledLayers(void) const
{
	std::vector<const char*> enabled_layers;
	enabled_layers.reserve(m_layers.size());
	for(auto& layer : m_layers)
	{
		enabled_layers.push_back(layer.c_str());
	}
	return enabled_layers;
}

std::vector<const char*> Instance::GetEnabledExtensions(void) const
{
	assert(m_extensions.size() > 0);
	std::vector<const char*> enabled_extensions;
	enabled_extensions.reserve(m_extensions.size());
	for (auto& extension : m_extensions)
	{
		enabled_extensions.push_back(extension.c_str());
	}
	return enabled_extensions;
}

VkApplicationInfo Instance::ApplicationInfo(void)
{
	VkApplicationInfo application_info = {};
	application_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.pNext = nullptr;
	application_info.pApplicationName = nullptr;
	application_info.applicationVersion = VK_API_VERSION_1_0;
	application_info.pEngineName = nullptr;
	application_info.engineVersion = VK_API_VERSION_1_0;
	application_info.apiVersion = VK_API_VERSION_1_0;
	return application_info;
}

VkInstanceCreateInfo Instance::CreateInfo(void)
{
	VkInstanceCreateInfo instance_create_info = {};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pNext = nullptr;
	instance_create_info.flags = 0;
	instance_create_info.pApplicationInfo = nullptr;
	instance_create_info.enabledLayerCount = 0;
	instance_create_info.ppEnabledLayerNames = nullptr;
	instance_create_info.enabledExtensionCount = 0;
	instance_create_info.ppEnabledExtensionNames = nullptr;
	return instance_create_info;
}

} /* namespace Vulkan */
