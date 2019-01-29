/*
 * VulkanSurface.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANSURFACE_H_
#define VULKAN_VULKANSURFACE_H_

#include "VulkanObject.h"
#include <vector>

namespace Vulkan
{
class PhysicalDevice;
class ROOKY_EXPORT Surface: public Object
{
private:
	explicit Surface(PhysicalDevice* physical);
	virtual ~Surface(void) override;

public:
	VkResult Create(xcb_connection_t* connection, xcb_window_t window);

public:
	VkPresentModeKHR GetPresentMode(bool vsync) const;
	VkCompositeAlphaFlagBitsKHR GetCompositeAlphaFlag(void) const;
	VkSurfaceTransformFlagBitsKHR GetTransformFlag(void) const;

public:
	inline VkSurfaceKHR GetHandle(void) const { return m_surface; }
	inline PhysicalDevice* GetInstance(void) const { return m_physicalDevice; }

public:
	inline const VkSurfaceCapabilitiesKHR& GetCapabilities(void) const { return m_capabilities; }
	inline const VkSurfaceFormatKHR& GetFormat(uint32_t index) const { return m_formats.at(index); }

public:
	inline xcb_window_t GetWindow(void) const { return m_window; }
	inline xcb_connection_t* GetConnection(void) const { return m_connection; }

public:
	static inline Surface* New(PhysicalDevice* physical) { return new Surface(physical); }

public:
	static VkXcbSurfaceCreateInfoKHR CreateInfo(void);

private:
	VkResult Create(const VkXcbSurfaceCreateInfoKHR* info);

private:
	xcb_connection_t* m_connection = nullptr;
	xcb_window_t m_window = 0;

public:
	PhysicalDevice* m_physicalDevice = nullptr;
	VkSurfaceKHR m_surface = VK_NULL_HANDLE;
	VkSurfaceCapabilitiesKHR m_capabilities = {};
	std::vector<VkSurfaceFormatKHR> m_formats;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANSURFACE_H_ */
