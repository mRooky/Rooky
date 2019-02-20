/*
 * VKVertexInputBinding.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTBINDING_HPP_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTBINDING_HPP_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class VertexInputBinding: public VkVertexInputBindingDescription
{
public:
	VertexInputBinding(void) = default;
	~VertexInputBinding(void) = default;

public:
	inline void SetContent(uint32_t binding, uint32_t stride, VkVertexInputRate rate)
	{
		this->binding  = binding;
		this->stride = stride;
		this->inputRate = rate;
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTBINDING_HPP_ */
