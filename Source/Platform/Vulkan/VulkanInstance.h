/*
 * VulkanInstance.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANINSTANCE_H_
#define VULKAN_VULKANINSTANCE_H_

#include <vector>
#include <string>
#include "VulkanObject.h"

namespace Vulkan
{
class Debug;
class ROOKY_EXPORT Instance: public Object
{
	Instance(void);
	virtual ~Instance(void) override;

public:
	VkResult Create(const char* name, bool debug = false);

public:
	void EnableLayer(const char* layer);
	void EnableExtension(const char* extension);

public:
	inline VkInstance GetHandle(void) const { return m_instance; }

public:
	static inline Instance* New(void) { return new Instance; }

public:
	static VkApplicationInfo ApplicationInfo(void);
	static VkInstanceCreateInfo CreateInfo(void);

private:
	void CreateDebugReport(bool debug);

private:
	VkResult Create(const VkInstanceCreateInfo* info);

private:
	std::vector<const char*> GetEnabledLayers(void) const;
	std::vector<const char*> GetEnabledExtensions(void) const;

private:
	VkInstance m_instance = VK_NULL_HANDLE;

private:
	Debug* m_debug = nullptr;
	VkDebugReportCallbackCreateInfoEXT m_debugReport = {};

private:
	std::vector<std::string> m_layers;
	std::vector<std::string> m_extensions;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANINSTANCE_H_ */
