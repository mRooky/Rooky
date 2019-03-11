/*
 * VulkanDescriptorSetLayout.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDESCRIPTORSETLAYOUT_H_
#define VULKAN_VULKANDESCRIPTORSETLAYOUT_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class ROOKY_EXPORT DescriptorSetLayout: public DeviceObject
{
	friend class DescriptorPool;
private:
	explicit DescriptorSetLayout(Device* device);
	virtual ~DescriptorSetLayout(void) override;

public:
	VkResult Create(const std::vector<VkDescriptorSetLayoutBinding>& bindings);
	VkResult Create(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	bool IsCreateBy(const std::vector<VkDescriptorSetLayoutBinding>& bindings) const;
	bool IsCreateBy(uint32_t count, const VkDescriptorSetLayoutBinding* bindings) const;

public:
	inline VkDescriptorSetLayout GetHandle(void) const { return m_layout; }

public:
	static inline DescriptorSetLayout* New(Device* device) { return new DescriptorSetLayout(device); }

public:
	static VkDescriptorSetLayoutBinding Binding(void);
	static VkDescriptorSetLayoutCreateInfo CreateInfo(void);

protected:
	virtual void Destroy(void) override { delete this; }

private:
	VkResult Create(const VkDescriptorSetLayoutCreateInfo* info);

private:
	VkDescriptorSetLayout m_layout = VK_NULL_HANDLE;
	std::vector<VkDescriptorSetLayoutBinding> mBindings;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDESCRIPTORSETLAYOUT_H_ */
