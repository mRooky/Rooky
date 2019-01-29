/*
 * VulkanVendor.cpp
 *
 *  Created on: Dec 8, 2018
 *      Author: rookyma
 */

#include "VulkanVendor.h"
#include "VulkanDefine.h"
#include <algorithm>
#include <sstream>

namespace Vulkan
{

Vendor::Vendor(void)
{
}

Vendor::~Vendor(void)
{
	m_layerNames.clear();
	m_extensionNames.clear();
}

void Vendor::Init(void)
{
	GetLayers();
	uint32_t version = 0;
	vkEnumerateInstanceVersion(&version);
	m_major = VK_VERSION_MAJOR(version);
	m_minor = VK_VERSION_MINOR(version);
	m_patch = VK_VERSION_PATCH(version);
}

std::string Vendor::GetVersion(void) const
{
	std::stringstream ss;
	ss << "Vulkan Version : " << m_major << "." << m_minor << "." << m_patch;
	return ss.str();
}

bool Vendor::DoesLayerExist(const char* layer) const
{
	std::string name(layer);
	auto iterator = std::find(m_layerNames.begin(), m_layerNames.end(), name);
	return iterator != m_layerNames.end();
}

bool Vendor::DoesExtensionExist(const char* extension) const
{
	std::string name(extension);
	auto iterator = std::find(m_extensionNames.begin(), m_extensionNames.end(), name);
	return iterator != m_extensionNames.end();
}

void Vendor::GetLayers(void)
{
	uint32_t count = 0;
	VkResult result = vkEnumerateInstanceLayerProperties(&count, nullptr);
	VK_RESULT_CHECK(result, VK_SUCCESS);
	std::vector<VkLayerProperties> layer_properties;
	if (count > 0 && result == VK_SUCCESS)
	{
		layer_properties.resize(count);
		result = vkEnumerateInstanceLayerProperties(&count, layer_properties.data());
		VK_RESULT_CHECK(result, VK_SUCCESS);
	}
	GetExtensions(nullptr);
	for (auto& property : layer_properties)
	{
		m_layerNames.push_back(property.layerName);
		std::cout << "[LAYER] : " << property.layerName << std::endl;
		GetExtensions(property.layerName);
	}
}

void Vendor::GetExtensions(const char* layer)
{
	uint32_t count = 0;
	VkResult result = vkEnumerateInstanceExtensionProperties(layer, &count, nullptr);
	std::vector<VkExtensionProperties> extension_properties;
	if (count != 0 && result == VK_SUCCESS)
	{
		extension_properties.resize(count);
		result = vkEnumerateInstanceExtensionProperties(layer, &count, extension_properties.data());
		VK_RESULT_CHECK(result, VK_SUCCESS);
		for (auto& property : extension_properties)
		{
			auto find = std::find(m_extensionNames.begin(), m_extensionNames.end(), property.extensionName);
			if (find == m_extensionNames.end())
			{
				m_extensionNames.push_back(property.extensionName);
				std::cout << "[EXTENSION] : " << property.extensionName << std::endl;
			}
		}
	}
}

std::string Vendor::VersionString(uint32_t version)
{
	uint32_t major = VK_VERSION_MAJOR(version);
	uint32_t minor = VK_VERSION_MINOR(version);
	uint32_t patch = VK_VERSION_PATCH(version);
	std::stringstream ss;
	ss << "API Version : " << major << "." << minor << "." << patch;
	return ss.str();
}

} /* namespace Vulkan */
