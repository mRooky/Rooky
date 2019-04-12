/*
 * VulkanFence.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANFENCE_H_
#define VULKAN_VULKANFENCE_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class Device;
class VULKAN_EXPORT Fence: public DeviceObject
{
private:
	explicit Fence(Device* device);
	virtual ~Fence(void) override;

public:
	VkResult Create(void);

public:
	VkResult GetStatus(void) const;
	VkResult WaitFor(VkBool32 all = VK_TRUE, uint64_t timeout = UINT32_MAX);
	VkResult Reset(void);

public:
	inline VkFence GetHandle(void) const { return m_fence; }

public:
	static inline Fence* New(Device* device) { return new Fence(device); }

public:
	static VkFenceCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkFenceCreateInfo* info);

private:
	VkFence m_fence = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANFENCE_H_ */
