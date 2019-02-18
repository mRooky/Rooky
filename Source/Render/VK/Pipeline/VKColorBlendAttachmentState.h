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
	void SetColor(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation);
	void SetAlpha(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation);

public:
	inline void Enable(bool enabled)
	{
		this->blendEnable = enabled ? VK_TRUE : VK_FALSE;
	}

public:
	static VkBlendFactor ConvertBlendFactor(Render::BlendFactor factor);
	static VkBlendOp ConverBlendOperation(Render::BlendOperation operaion);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDATTACHMENTSTATE_H_ */
