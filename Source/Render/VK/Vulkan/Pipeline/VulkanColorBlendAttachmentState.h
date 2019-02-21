/*
 * VKColorBlendAttachmentState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDATTACHMENTSTATE_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDATTACHMENTSTATE_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class ColorBlendAttachmentState: public VkPipelineColorBlendAttachmentState
{
public:
	ColorBlendAttachmentState(void);
	~ColorBlendAttachmentState(void);

public:
	void BlendEnable(bool enabled);

public:
	inline void SetColor(VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation)
	{
		this->srcColorBlendFactor = src;
		this->dstColorBlendFactor = dst;
		this->colorBlendOp = operation;
	}

	inline void SetAlpha(VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation)
	{
		this->srcAlphaBlendFactor = src;
		this->dstAlphaBlendFactor = dst;
		this->alphaBlendOp = operation;
	}

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDATTACHMENTSTATE_H_ */
