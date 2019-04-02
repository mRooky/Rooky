/*
 * VulkanDescriptorSet.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDESCRIPTORSET_H_
#define VULKAN_VULKANDESCRIPTORSET_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class DescriptorPool;
class DescriptorSetLayout;
class ROOKY_EXPORT DescriptorSet: public DeviceObject
{
	friend class DescriptorPool;
private:
	explicit DescriptorSet(Device* device);
	virtual ~DescriptorSet(void) override;

public:
	VkResult Create(DescriptorPool* pool, DescriptorSetLayout* layout);

public:
	inline VkDescriptorSet GetHandle(void) const { return m_set; }
	inline DescriptorSetLayout* GetLayout(void) const { return m_layout; }

public:
	static inline DescriptorSet* New(Device* device) { return new DescriptorSet(device); }

public:
	static VkDescriptorSetAllocateInfo AllocateInfo(void);
	static VkWriteDescriptorSet WriteDescriptorSet(void);

public:
	static void UpdateSets(Device* device, const std::vector<VkWriteDescriptorSet>& writes);
	static void UpdateSets(Device* device, uint32_t count, const VkWriteDescriptorSet* write);

protected:
	virtual void Destroy(void) override { delete this; }

private:
	VkResult Create(const VkDescriptorSetAllocateInfo* info);

private:
	DescriptorPool* m_pool = nullptr;
	VkDescriptorSet m_set = VK_NULL_HANDLE;
	DescriptorSetLayout* m_layout = nullptr;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDESCRIPTORSET_H_ */
