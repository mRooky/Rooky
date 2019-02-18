/*
 * VKShaderStageCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGECREATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGECREATEINFO_H_

#include <vulkan/vulkan_core.h>

namespace VK
{

class ShaderStageCreateInfo : public VkPipelineShaderStageCreateInfo
{
public:
	ShaderStageCreateInfo(void);
	~ShaderStageCreateInfo(void);

public:
	inline void SetContent(VkShaderModule module, VkShaderStageFlagBits stage)
	{
		this->stage = stage;
		this->module = module;
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKSHADERSTAGECREATEINFO_H_ */
