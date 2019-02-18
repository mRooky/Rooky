/*
 * VKVertexInputAttribute.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTATTRIBUTE_HPP_
#define SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTATTRIBUTE_HPP_

#include "RenderFormat.h"

#include "VKFormat.h"

#include <vulkan/vulkan_core.h>

namespace VK
{

class VertexInputAttribute: public VkVertexInputAttributeDescription
{
public:
	VertexInputAttribute(void) = default;
	~VertexInputAttribute(void) = default;

public:
	inline void SetContent(uint32_t location, uint32_t binding, Render::Format format, uint32_t offset)
	{
		this->location = location;
		this->binding = binding;
		this->format = ConvertFormat(format);
		this->offset = offset;
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTATTRIBUTE_HPP_ */
