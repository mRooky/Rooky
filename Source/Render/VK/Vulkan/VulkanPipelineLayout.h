/*
 * VulkanPipelineLayout.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANPIPELINELAYOUT_H_
#define VULKAN_VULKANPIPELINELAYOUT_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class DescriptorSetLayout;
class ROOKY_EXPORT PipelineLayout: public DeviceObject
{
private:
	explicit PipelineLayout(Device* device);
	virtual ~PipelineLayout(void) override;

public:
	VkResult Create(const std::vector<DescriptorSetLayout*>& layouts);
	VkResult Create(const std::vector<VkDescriptorSetLayout>& layouts);
	VkResult Create(const std::vector<VkDescriptorSetLayout>& layouts, const std::vector<VkPushConstantRange>& ranges);
	VkResult Create(const std::vector<DescriptorSetLayout*>& layouts, uint32_t count, const VkPushConstantRange* ranges);

public:
	inline VkPipelineLayout GetHandle(void) const { return m_layout; }

public:
	static inline PipelineLayout* New(Device* device) { return new PipelineLayout(device); }

public:
	static VkPipelineLayoutCreateInfo CreateInfo(void);

public:
	VkResult Create(const VkPipelineLayoutCreateInfo* info);

private:
	VkPipelineLayout m_layout = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANPIPELINELAYOUT_H_ */
