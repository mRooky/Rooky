/*
 * VKVertexInputStateCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTSTATEINFO_H_

#include "VKVertexInputBinding.hpp"
#include "VKVertexInputAttribute.hpp"
#include <vulkan/vulkan_core.h>
#include <vector>

namespace VK
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

#endif /* SOURCE_RENDER_VK_PIPELINE_VKVERTEXINPUTSTATEINFO_H_ */
