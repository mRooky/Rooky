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
	ShaderStageInfo* CreateShaderStage(void);

public:
	inline size_t GetShaderStageCount(void) { return m_shaderStages.size(); }
	inline const ShaderStageInfo& GetShaderStageInfo(size_t index) { return m_shaderStages.at(index); }
	inline const VkComputePipelineCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	std::vector<ShaderStageInfo> m_shaderStages;
	VkComputePipelineCreateInfo m_createInfo = {};
};

} /* namespace Vulkan */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOMPUTEPIPELINEINFO_H_ */
