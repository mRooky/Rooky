/*
 * VulkanCommandPool.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANCOMMANDPOOL_H_
#define VULKAN_VULKANCOMMANDPOOL_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class CommandBuffer;
class ROOKY_EXPORT CommandPool: public DeviceObject
{
private:
	explicit CommandPool(Device* device);
	virtual ~CommandPool(void) override;

public:
	VkResult Create(uint32_t family);

public:
	CommandBuffer* Allocate(VkCommandBufferLevel level);

public:
	inline VkCommandPool GetHandle(void) const { return m_pool; }
	inline uint32_t GetFamily(void) const { return m_family; }

public:
	static inline CommandPool* New(Device* device) { return new CommandPool(device); }

public:
	static VkCommandPoolCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkCommandPoolCreateInfo* info);

private:
	uint32_t m_family = ~0u;
	VkCommandPool m_pool = VK_NULL_HANDLE;

private:
	std::vector<CommandBuffer*> m_buffers;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANCOMMANDPOOL_H_ */
