/*
 * VKColorBlendAttachmentState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDATTACHMENTSTATE_H_
#define SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDATTACHMENTSTATE_H_

#include "RenderTypes.h"

#include <vulkan/vulkan_core.h>

namespace VK
{

class ColorBlendAttachmentState: public VkPipelineColorBlendAttachmentState
{
public:
	ColorBlendAttachmentState(void);
	~ColorBlendAttachmentState(void);

public:
	inline void SetColor(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation)
	{
		this->srcColorBlendFactor = ColorBlendAttachmentState::Convert(src);
		this->dstColorBlendFactor = ColorBlendAttachmentState::Convert(dst);
		this->colorBlendOp = ColorBlendAttachmentState::Convert(operation);
	}

	inline void SetAlpha(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation)
	{
		this->srcAlphaBlendFactor = ColorBlendAttachmentState::Convert(src);
		this->dstAlphaBlendFactor = ColorBlendAttachmentState::Convert(dst);
		this->alphaBlendOp = ColorBlendAttachmentState::Convert(operation);
	}

public:
	inline void Enable(bool enabled)
	{
		this->blendEnable = enabled ? VK_TRUE : VK_FALSE;
	}

public:
	static VkBlendFactor Convert(Render::BlendFactor factor);
	static VkBlendOp Convert(Render::BlendOperation operaion);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDATTACHMENTSTATE_H_ */
