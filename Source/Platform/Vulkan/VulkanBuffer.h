/*
 * VulkanBuffer.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANBUFFER_H_
#define VULKAN_VULKANBUFFER_H_

#include "VulkanResource.h"

namespace Vulkan
{
class VULKAN_EXPORT Buffer: public Resource
{
private:
	explicit Buffer(Device* device);
	virtual ~Buffer(void) override;

public:
	VkResult Create(VkDeviceSize size, VkBufferUsageFlags usage);

public:
	void WriteData(VkDeviceSize offset, VkDeviceSize size, const void* src);
	void ReadData(VkDeviceSize offset, VkDeviceSize size, void* dst);

public:
	VkDescriptorBufferInfo GetDescriptorInfo(void) const;

public:
	virtual VkResult BindMemory(DeviceMemory* memory, VkDeviceSize offset) override;

public:
	inline VkBuffer GetHandle(void) const { return m_buffer; }
	inline VkDeviceSize GetSize(void) const { return m_info.size; }
	inline VkBufferUsageFlags GetUsage(void) const { return m_info.usage; }

public:
	inline const VkBufferCreateInfo& GetInfo(void) const { return m_info; }

public:
	static inline Buffer* New(Device* device) { return new Buffer(device); }

public:
	static VkBufferCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkBufferCreateInfo* info);

private:
	VkBuffer m_buffer = VK_NULL_HANDLE;
	VkBufferCreateInfo m_info = {};
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANBUFFER_H_ */
