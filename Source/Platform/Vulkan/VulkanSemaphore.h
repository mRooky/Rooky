/*
 * VulkanSemaphore.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANSEMAPHORE_H_
#define VULKAN_VULKANSEMAPHORE_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class VULKAN_EXPORT Semaphore: public DeviceObject
{
private:
	explicit Semaphore(Device* device);
	virtual ~Semaphore(void) override;

public:
	VkResult Create(void);

public:
	inline VkSemaphore GetHandle(void) const { return m_semaphore; }

public:
	static inline Semaphore* New(Device* device) { return new Semaphore(device); }

public:
	static VkSemaphoreCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkSemaphoreCreateInfo* info);

private:
	VkSemaphore m_semaphore = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANSEMAPHORE_H_ */
