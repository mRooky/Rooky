/*
 * VulkanQueue.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANQUEUE_H_
#define VULKAN_VULKANQUEUE_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class Fence;
class CommandBuffer;
class VULKAN_EXPORT Queue: public DeviceObject
{
private:
	explicit Queue(Device* device);
	virtual ~Queue(void) override;

public:
	VkResult Create(uint32_t family, uint32_t index);

public:
	void FlushCommandBuffer(CommandBuffer* buffer);

public:
	void Submit(const std::vector<VkSubmitInfo>& infos);
	void Submit(uint32_t count, const VkSubmitInfo* info);
	void Submit(const std::vector<VkCommandBuffer>& buffers, const std::vector<VkSemaphore>& semaphores);

public:
	void Present(const VkPresentInfoKHR* info);

public:
	inline uint32_t GetFamily(void) const { return m_family; }
	inline uint32_t GetIndex(void) const { return m_index; }
	inline VkQueue GetHandle(void) const { return m_queue; }

public:
	inline const VkQueueFamilyProperties& GetProperties(void) const { return m_properties; }

public:
	static inline Queue* New(Device* device) { return new Queue(device); }

public:
	static VkDeviceQueueCreateInfo CreateInfo(void);
	static VkSubmitInfo SubmitInfo(void);
	static VkPresentInfoKHR PresentInfo(void);

private:
	VkQueue m_queue = VK_NULL_HANDLE;
	Fence* m_fence = nullptr;
	uint32_t m_family = 0;
	uint32_t m_index = 0;
	VkQueueFamilyProperties m_properties = {};
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANQUEUE_H_ */
