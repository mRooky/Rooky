/*
 * VulkanShaderModule.h
 *
 *  Created on: Aug 28, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANSHADERMODULE_H_
#define VULKAN_VULKANSHADERMODULE_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{

class ROOKY_EXPORT ShaderModule : public DeviceObject
{
private:
	explicit ShaderModule(Device* device);
	virtual ~ShaderModule(void) override;

public:
	VkResult Create(size_t size, void* code);

public:
	VkPipelineShaderStageCreateInfo GetStageCreateInfo(VkShaderStageFlagBits stage) const;

public:
	inline VkShaderModule GetHandle(void) const { return m_shaderModule; }

public:
	static inline ShaderModule* New(Device* device) { return new ShaderModule(device); }

public:
	static VkShaderModuleCreateInfo CreateInfo(void);
	static std::vector<char> GetSpirVString(const char* file);

private:
	VkResult Create(const VkShaderModuleCreateInfo* info);

private:
	VkShaderModule m_shaderModule = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANSHADERMODULE_H_ */
