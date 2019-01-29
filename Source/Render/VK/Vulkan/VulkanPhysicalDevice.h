/*
 * VulkanPhysicalDevice.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANPHYSICALDEVICE_H_
#define VULKAN_VULKANPHYSICALDEVICE_H_

#include "VulkanObject.h"
#include <vector>

namespace Vulkan
{
class Instance;
class ROOKY_EXPORT PhysicalDevice: public Object
{
private:
	PhysicalDevice(Instance* instance);
	virtual ~PhysicalDevice(void) override;

public:
	VkResult Create(VkQueueFlags flags);

public:
	inline uint32_t GetFamily(void) const { return m_family; }
	inline VkQueueFlags GetQueueFalgs(void) const { return m_flags; }
	inline Instance* GetInstance(void) const { return m_instance; }
	inline VkPhysicalDevice GetHandle(void) const { return m_physicalDevice; }

public:
	inline const VkPhysicalDeviceFeatures& GetFeatures(void) const { return m_features; }
	inline const VkPhysicalDeviceProperties& GetProperties(void) const { return m_properties; }
	inline const VkPhysicalDeviceMemoryProperties& GetMemoryProperties(void) const { return m_memoryProperties; }
	inline const VkQueueFamilyProperties& GetQueueFamilyProperties(uint32_t index) const { return m_familyProperties.at(index); }

public:
	uint32_t GetMemoryTypeIndex(uint32_t bits, VkMemoryPropertyFlags flag) const;
	VkFormatProperties GetFormatProperties(VkFormat format) const;
	VkFormat GetDepthStencilFormat(void) const;
	VkImageTiling GetFormatTiling(VkFormat format, VkFormatFeatureFlags feature) const;

public:
	static inline PhysicalDevice* New(Instance* instance) { return new PhysicalDevice(instance); }

private:
	void InitializeProperties(void);
	bool QueryQueueFlags(VkPhysicalDevice physical);

private:
	Instance* m_instance = nullptr;
	uint32_t m_family = 0;
	VkQueueFlags m_flags = 0;
	VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;

private:
	VkPhysicalDeviceFeatures m_features = {};
	VkPhysicalDeviceProperties m_properties = {};
	VkPhysicalDeviceMemoryProperties m_memoryProperties = {};
	std::vector<VkQueueFamilyProperties> m_familyProperties;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANPHYSICALDEVICE_H_ */
