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

class ComputePipelineInfo
{
public:
	ComputePipelineInfo(void);
	virtual ~ComputePipelineInfo(void);

public:
	void SetLayout(PipelineLayout* layout);

public:
	inline void SetShaderStage(const ShaderStageInfo& stage) { m_createInfo.stage = stage; }
	inline const VkComputePipelineCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	VkComputePipelineCreateInfo m_createInfo = {};
};

} /* namespace Vulkan */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOMPUTEPIPELINEINFO_H_ */
