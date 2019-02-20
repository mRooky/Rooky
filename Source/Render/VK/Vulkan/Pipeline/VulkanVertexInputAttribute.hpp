/*
 * VKVertexInputAttribute.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTATTRIBUTE_HPP_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTATTRIBUTE_HPP_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class VertexInputAttribute: public VkVertexInputAttributeDescription
{
public:
	VertexInputAttribute(void) = default;
	~VertexInputAttribute(void) = default;

public:
	inline void SetContent(uint32_t location, uint32_t binding, VkFormat format, uint32_t offset)
	{
		this->location = location;
		this->binding = binding;
		this->format = format;
		this->offset = offset;
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTATTRIBUTE_HPP_ */
