/*
 * VKShaderStageCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANSHADERSTAGEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANSHADERSTAGEINFO_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class ShaderStageInfo : public VkPipelineShaderStageCreateInfo
{
public:
	ShaderStageInfo(void);
	~ShaderStageInfo(void);

public:
	inline void SetContent(VkShaderModule module, VkShaderStageFlagBits stage)
	{
		this->module = module;
		this->stage = stage;
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANSHADERSTAGEINFO_H_ */
