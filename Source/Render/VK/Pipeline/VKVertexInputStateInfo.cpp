/*
 * VKVertexInputStateCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKVertexInputStateInfo.h"
#include "VulkanPipeline.h"

namespace VK
{

VertexInputStateInfo::VertexInputStateInfo(void)
{
	*static_cast<VkPipelineVertexInputStateCreateInfo*>(this) = Vulkan::Pipeline::VertexInputStateCreateInfo();
}

VertexInputStateInfo::~VertexInputStateInfo(void)
{
}

VertexInputBinding* VertexInputStateInfo::CreateBinding(void)
{
	m_vertexInputBindings.push_back(VertexInputBinding());
	this->vertexBindingDescriptionCount = m_vertexInputBindings.size();
	this->pVertexBindingDescriptions = m_vertexInputBindings.data();
	return &m_vertexInputBindings.back();
}

VertexInputAttribute* VertexInputStateInfo::CreateAttribute(void)
{
	m_vertexInputAttributes.push_back(VertexInputAttribute());
	this->vertexAttributeDescriptionCount = m_vertexInputAttributes.size();
	this->pVertexAttributeDescriptions = m_vertexInputAttributes.data();
	return &m_vertexInputAttributes.back();
}

} /* namespace VK */
