/*
 * VulkanDebug.h
 *
 *  Created on: Sep 25, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDEBUG_H_
#define VULKAN_VULKANDEBUG_H_

#include "VulkanObject.h"

namespace Vulkan
{
class Instance;
class VULKAN_EXPORT Debug : public Object
{
private:
	Debug(Instance* instance);
	virtual ~Debug(void) override;

public:
	void Create(const VkDebugReportCallbackCreateInfoEXT* info);

public:
	static VkDebugReportCallbackCreateInfoEXT CreateInfo(void);

public:
	static Debug* New(Instance* instance) { return new Debug(instance); }

private:
	static VKAPI_ATTR VkBool32 Function(
			VkFlags flags,
			VkDebugReportObjectTypeEXT obj,
			uint64_t src,
			size_t location,
			int32_t code,
			const char* layer,
			const char* msg,
			void* data);

private:
	Instance* mInstance = nullptr;
	VkDebugReportCallbackEXT m_debug = VK_NULL_HANDLE;
	PFN_vkCreateDebugReportCallbackEXT m_creator = nullptr;
	PFN_vkDestroyDebugReportCallbackEXT m_deleter = nullptr;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDEBUG_H_ */
