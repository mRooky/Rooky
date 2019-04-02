/*
 * VulkanSwapChain.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANSWAPCHAIN_H_
#define VULKAN_VULKANSWAPCHAIN_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class SwapChainImage;
class Surface;
class Fence;
class Semaphore;
class ROOKY_EXPORT SwapChain: public DeviceObject
{
private:
	explicit SwapChain(Device* device);
	virtual ~SwapChain(void) override;

public:
	VkResult Create(Surface* surface);

public:
	uint32_t AcquireNextImage(void);

public:
	inline Surface* GetSurface(void) const { return m_surface; }
	inline VkSwapchainKHR GetHandle(void) const { return m_swapchain; }
	inline SwapChainImage* GetImage(uint32_t index) const { return m_images.at(index); }
	inline Fence* GetFence(void) const { return m_fence; }
	inline Semaphore* GetSemaphore(void) const { return m_semaphore; }
	inline uint32_t GetImageIndex(void) const { return m_index; }

public:
	static inline SwapChain* New(Device* device) { return new SwapChain(device); }

public:
	static VkSwapchainCreateInfoKHR CreateInfo(void);

private:
	void CreateImage(void);
	void CreateSynchronization(void);

private:
	VkResult Create(const VkSwapchainCreateInfoKHR* info);

private:
	Surface* m_surface = nullptr;
	VkSwapchainKHR m_swapchain = VK_NULL_HANDLE;
	VkSwapchainCreateInfoKHR m_info = {};
	std::vector<SwapChainImage*> m_images;

private:
	uint32_t m_index = 0;
	Fence* m_fence = nullptr;
	Semaphore* m_semaphore = nullptr;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANSWAPCHAIN_H_ */
