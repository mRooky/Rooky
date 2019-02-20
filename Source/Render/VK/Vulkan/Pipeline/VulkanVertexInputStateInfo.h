/*
 * VKVertexInputStateCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_

#include "VulkanVertexInputAttribute.hpp"
#include "VulkanVertexInputBinding.hpp"
#include <vector>

namespace Vulkan
{

class VertexInputStateInfo: public VkPipelineVertexInputStateCreateInfo
{
public:
	VertexInputStateInfo(void);
	~VertexInputStateInfo(void);

public:
	VertexInputBinding* CreateBinding(void);
	VertexInputAttribute* CreateAttribute(void);

private:
	std::vector<VertexInputBinding> m_vertexInputBindings;
	std::vector<VertexInputAttribute> m_vertexInputAttributes;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_ */
