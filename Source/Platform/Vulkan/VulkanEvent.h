/*
 * VulkanEvent.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANEVENT_H_
#define VULKAN_VULKANEVENT_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class Device;
class VULKAN_EXPORT Event: public DeviceObject
{
private:
	explicit Event(Device* device);
	virtual ~Event(void) override;

public:
	VkResult Create(void);

public:
	inline VkEvent GetHandle(void) const { return m_event; }

public:
	static inline Event* New(Device* device) { return new Event(device); }

public:
	static VkEventCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkEventCreateInfo* info);

private:
	VkEvent m_event = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANEVENT_H_ */
