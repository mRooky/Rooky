/*
 * VKShaderStageCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGEINFO_H_

#include "RenderTypes.h"
#include <vulkan/vulkan_core.h>

namespace VK
{

class ShaderStageInfo : public VkPipelineShaderStageCreateInfo
{
public:
	ShaderStageInfo(void);
	~ShaderStageInfo(void);

public:
	inline void SetContent(VkShaderModule module, Render::ShaderStage stage)
	{
		this->module = module;
		this->stage = ShaderStageInfo::Convert(stage);
	}

public:
	static VkShaderStageFlagBits Convert(Render::ShaderStage stage);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGEINFO_H_ */
