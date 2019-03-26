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

VkVertexInputBindingDescription* VertexInputStateInfo::GetBinding(uint32_t binding)
{
	for (auto& exist : m_vertexInputBindings)
	{
		if (exist.binding == binding)
		{
			return &exist;
		}
	}
	VkVertexInputBindingDescription input_binding = {};
	input_binding.binding = binding;
	m_vertexInputBindings.push_back(input_binding);
	m_createInfo.vertexBindingDescriptionCount = m_vertexInputBindings.size();
	m_createInfo.pVertexBindingDescriptions = m_vertexInputBindings.data();
	return &m_vertexInputBindings.back();
}

VkVertexInputAttributeDescription* VertexInputStateInfo::GetAttribute(uint32_t binding, uint32_t location)
{
	for (auto& attribute : m_vertexInputAttributes)
	{
		if (attribute.binding == binding && attribute.location == location)
		{
			return &attribute;
		}
	}
	VkVertexInputAttributeDescription input_attribute = {};
	input_attribute.binding = binding;
	input_attribute.location = location;
	m_vertexInputAttributes.push_back(input_attribute);
	m_createInfo.vertexAttributeDescriptionCount = m_vertexInputAttributes.size();
	m_createInfo.pVertexAttributeDescriptions = m_vertexInputAttributes.data();
	return &m_vertexInputAttributes.back();
}

} /* namespace VK */
