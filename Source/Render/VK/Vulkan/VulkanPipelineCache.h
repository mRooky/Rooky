/*
 * VulkanPipelineCache.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANPIPELINECACHE_H_
#define VULKAN_VULKANPIPELINECACHE_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class ROOKY_EXPORT PipelineCache: public DeviceObject
{
private:
	explicit PipelineCache(Device* device);
	virtual ~PipelineCache(void) override;

public:
	VkResult Create(uint32_t size, const void* data);

public:
	inline VkPipelineCache GetHandle(void) const { return m_cache; }

public:
	static inline PipelineCache* New(Device* device) { return new PipelineCache(device); }

public:
	static VkPipelineCacheCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkPipelineCacheCreateInfo* info);

private:
	VkPipelineCache m_cache = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANPIPELINECACHE_H_ */
