/*
 * VulkanBufferView.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANBUFFERVIEW_H_
#define VULKAN_VULKANBUFFERVIEW_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class Buffer;
class ROOKY_EXPORT BufferView: public DeviceObject
{
private:
	explicit BufferView(Device* device);
	virtual ~BufferView(void) override;

public:
	VkResult Create(Buffer* buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range);

public:
	inline VkBufferView GetView(void) const { return m_view; }

public:
	static inline BufferView* New(Device* device) { return new BufferView(device); }

public:
	static VkBufferViewCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkBufferViewCreateInfo* info);

private:
	Buffer* m_buffer = nullptr;
	VkBufferView m_view = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANBUFFERVIEW_H_ */
