/*
 * VulkanPipeline.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANPIPELINE_H_
#define VULKAN_VULKANPIPELINE_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class PipelineCache;
class PipelineLayout;
class ROOKY_EXPORT Pipeline: public DeviceObject
{
private:
	explicit Pipeline(Device* device);
	virtual ~Pipeline(void) override;

public:
	VkResult Create(PipelineCache* cache, const VkComputePipelineCreateInfo* info);
	VkResult Create(PipelineCache* cache, const VkGraphicsPipelineCreateInfo* info);

public:
	inline VkPipeline GetHandle(void) const { return m_pipeline; }
	inline VkPipelineBindPoint GetBindPoint(void) const { return m_point; }
	inline VkPipelineLayout GetLayout(void) const { return m_layout; }

public:
	static inline Pipeline* New(Device* device) { return new Pipeline(device); }

public:
	static VkGraphicsPipelineCreateInfo CreateInfo(void);

public:
	static VkPipelineShaderStageCreateInfo ShaderStageCreateInfo(void);
	static VkPipelineDynamicStateCreateInfo DynamicStateCreateInfo(void);
	static VkPipelineVertexInputStateCreateInfo VertexInputStateCreateInfo(void);
	static VkPipelineInputAssemblyStateCreateInfo InputAssemblyStateCreateInfo(void);
	static VkPipelineRasterizationStateCreateInfo RasterizationStateCreateInfo(void);
	static VkPipelineColorBlendStateCreateInfo ColorBlendStateCreateInfo(void);
	static VkPipelineColorBlendAttachmentState ColorBlendAttachmentState(bool blend);
	static VkPipelineViewportStateCreateInfo ViewportStateCreateInfo(void);
	static VkPipelineDepthStencilStateCreateInfo DepthStencilStateCreateInfo(void);
	static VkPipelineMultisampleStateCreateInfo MultisampleStateCreateInfo(void);

private:
	VkPipeline m_pipeline = VK_NULL_HANDLE;
	VkPipelineLayout m_layout = VK_NULL_HANDLE;
	VkPipelineBindPoint m_point = VK_PIPELINE_BIND_POINT_GRAPHICS;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANPIPELINE_H_ */
