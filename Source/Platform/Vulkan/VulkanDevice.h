/*
 * VulkanDevice.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDEVICE_H_
#define VULKAN_VULKANDEVICE_H_

#include "VulkanObject.h"
#include <vector>

namespace Vulkan
{
class Queue;
class PhysicalDevice;
class VULKAN_EXPORT Device: public Object
{
private:
	explicit Device(PhysicalDevice* physical);
	virtual ~Device(void) override;

public:
	VkResult Create(const VkDeviceCreateInfo* info);

public:
	Queue* GetQueue(uint32_t family, uint32_t index);

public:
	inline VkDevice GetHandle(void) const { return m_device; }
	inline PhysicalDevice* GetPhysicalDevice(void) const { return m_physicalDevice; }
	inline uint32_t GetQueueCount(void) const { return m_queues.size(); }

public:
	static VkDeviceCreateInfo CreateInfo(void);

public:
	static inline Device* New(PhysicalDevice* physical) { return new Device(physical);}

private:
	VkDevice m_device = VK_NULL_HANDLE;
	PhysicalDevice* m_physicalDevice = nullptr;
	std::vector<Queue*> m_queues;

};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDEVICE_H_ */
