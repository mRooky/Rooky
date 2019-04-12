/*
 * VulkanDeviceMemory.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDEVICEMEMORY_H_
#define VULKAN_VULKANDEVICEMEMORY_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class Device;
class Resource;
class VULKAN_EXPORT DeviceMemory: public DeviceObject
{
private:
	explicit DeviceMemory(Device* device);
	virtual ~DeviceMemory(void) override;

public:
	VkResult Allocate(Resource* resource, VkMemoryPropertyFlags properties);
	VkResult Allocate(VkDeviceSize size, uint32_t index , VkMemoryPropertyFlags properties);
	VkResult Allocate(const VkMemoryRequirements& requirements, VkMemoryPropertyFlags properties);

public:
	void* Map(VkDeviceSize offset, VkDeviceSize size);
	void Unmap(void);

public:
	void Flush(VkDeviceSize offset, VkDeviceSize size);
	void Flush(const std::vector<VkMappedMemoryRange>& ranges);

public:
	inline VkDeviceMemory GetHandle(void) const { return m_memory; }
	inline uint32_t GetMemoryTypeIndex(void) const { return m_typeIndex; }
	inline VkMemoryPropertyFlags GetPropertyFlags(void) const { return mProperties; }

public:
	static inline DeviceMemory* New(Device* device) { return new DeviceMemory(device); }

public:
	static VkMemoryAllocateInfo AllocateInfo(void);
	static VkMappedMemoryRange MappedRange(void);

private:
	VkResult Allocate(const VkMemoryAllocateInfo* info);

private:
	VkDeviceSize m_size = 0;
	uint32_t m_typeIndex = 0;
	VkDeviceMemory m_memory = VK_NULL_HANDLE;
	VkMemoryPropertyFlags mProperties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDEVICEMEMORY_H_ */
