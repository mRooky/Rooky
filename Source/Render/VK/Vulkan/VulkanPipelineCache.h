/*
 * VulkanPipelineCache.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANPIPELINECACHE_H_
#define VULKAN_VULKANPIPELINECACHE_H_

#include "VulkanDeviceObject.h"
#include <vector>

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
	inline size_t GetSize(void) const { return m_data.size(); }
	inline const uint8_t* GetData(void) const { return m_data.data(); }

public:
	static inline PipelineCache* New(Device* device) { return new PipelineCache(device); }

public:
	static VkPipelineCacheCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkPipelineCacheCreateInfo* info);

private:
	VkPipelineCache m_cache = VK_NULL_HANDLE;

private:
	std::vector<uint8_t> m_data;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANPIPELINECACHE_H_ */
