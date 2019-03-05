/*
 * VulkanComputePipelineInfo.h
 *
 *  Created on: Feb 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOMPUTEPIPELINEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOMPUTEPIPELINEINFO_H_

#include "VulkanPipelineStateInterfaces.h"

namespace Vulkan
{
class ShaderModule;
class ComputePipelineInfo
{
public:
	ComputePipelineInfo(void);
	virtual ~ComputePipelineInfo(void);

public:
	void SetLayout(PipelineLayout* layout);
	void SetShader(ShaderModule* shader, const char* entry);

public:
	inline const VkComputePipelineCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	PipelineLayout* m_pipelineLayout = nullptr;
	VkComputePipelineCreateInfo m_createInfo = {};
};

} /* namespace Vulkan */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOMPUTEPIPELINEINFO_H_ */
