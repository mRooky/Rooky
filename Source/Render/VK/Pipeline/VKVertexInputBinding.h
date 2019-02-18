/*
 * VKVertexInputBinding.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTBINDING_H_
#define SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTBINDING_H_

#include "RenderTypes.h"
#include "VKInline.h"

#include <vulkan/vulkan_core.h>

namespace VK
{

class VertexInputBinding: public VkVertexInputBindingDescription
{
public:
	VertexInputBinding(void) = default;
	~VertexInputBinding(void) = default;

public:
	inline void SetContent(uint32_t binding, uint32_t stride, Render::VertexInputRate rate)
	{
		this->binding  = binding;
		this->stride = stride;
		this->inputRate = ConvertRate(rate);
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTBINDING_H_ */
