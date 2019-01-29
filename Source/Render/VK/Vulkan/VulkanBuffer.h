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
class ROOKY_EXPORT Buffer: public Resource
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
	virtual VkResult BindMemory(DeviceMemory* memory, VkDeviceSize offset) override;

public:
	inline VkBuffer GetHandle(void) const { return m_buffer; }
	inline VkDeviceSize GetSize(void) const { return m_size; }
	inline VkBufferUsageFlags GetUsage(void) const { return m_usage; }

public:
	static inline Buffer* New(Device* device) { return new Buffer(device); }

public:
	static VkBufferCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkBufferCreateInfo* info);

private:
	VkBuffer m_buffer = VK_NULL_HANDLE;
	VkDeviceSize m_size = 0;
	VkBufferUsageFlags m_usage = VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANBUFFER_H_ */
