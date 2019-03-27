/*
 * VulkanDescriptorPool.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDESCRIPTORPOOL_H_
#define VULKAN_VULKANDESCRIPTORPOOL_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class DescriptorSet;
class DescriptorSetLayout;
class ROOKY_EXPORT DescriptorPool: public DeviceObject
{
private:
	explicit DescriptorPool(Device* device);
	virtual ~DescriptorPool(void) override;

public:
	VkResult Create(uint32_t max, std::vector<VkDescriptorPoolSize> sizes);

public:
	DescriptorSet* Allocate(DescriptorSetLayout* layout);
	DescriptorSet* Allocate(const std::vector<VkDescriptorSetLayoutBinding>& bindings);
	DescriptorSet* Allocate(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);
	DescriptorSetLayout* GetLayout(const std::vector<VkDescriptorSetLayoutBinding>& bindings);
	DescriptorSetLayout* GetLayout(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	inline VkDescriptorPool GetHandle(void) const { return m_pool; }

public:
	static inline DescriptorPool* New(Device* device) { return new DescriptorPool(device); }

public:
	static VkDescriptorPoolCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkDescriptorPoolCreateInfo* info);
	DescriptorSetLayout* FindLayout(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

private:
	VkDescriptorPool m_pool = VK_NULL_HANDLE;
	std::vector<DescriptorSet*> m_sets;
	std::vector<DescriptorSetLayout*> m_layouts;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDESCRIPTORPOOL_H_ */
