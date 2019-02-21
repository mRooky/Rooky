/*
 * VKVertexInputStateCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanVertexInputStateInfo.h"
#include "VulkanPipeline.h"

namespace Vulkan
{

VertexInputStateInfo::VertexInputStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::VertexInputStateCreateInfo();
}

VertexInputStateInfo::~VertexInputStateInfo(void)
{
}

VertexInputBinding* VertexInputStateInfo::CreateBinding(void)
{
	m_vertexInputBindings.push_back(VertexInputBinding());
	m_createInfo.vertexBindingDescriptionCount = m_vertexInputBindings.size();
	m_createInfo.pVertexBindingDescriptions = m_vertexInputBindings.data();
	return &m_vertexInputBindings.back();
}

VertexInputAttribute* VertexInputStateInfo::CreateAttribute(void)
{
	m_vertexInputAttributes.push_back(VertexInputAttribute());
	m_createInfo.vertexAttributeDescriptionCount = m_vertexInputAttributes.size();
	m_createInfo.pVertexAttributeDescriptions = m_vertexInputAttributes.data();
	return &m_vertexInputAttributes.back();
}

} /* namespace VK */
