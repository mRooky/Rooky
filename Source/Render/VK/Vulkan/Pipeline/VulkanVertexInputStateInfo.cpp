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

VkVertexInputBindingDescription* VertexInputStateInfo::CreateBinding(void)
{
	VkVertexInputBindingDescription input_binding = {};
	m_vertexInputBindings.push_back(input_binding);
	m_createInfo.vertexBindingDescriptionCount = m_vertexInputBindings.size();
	m_createInfo.pVertexBindingDescriptions = m_vertexInputBindings.data();
	return &m_vertexInputBindings.back();
}

VkVertexInputAttributeDescription* VertexInputStateInfo::CreateAttribute(void)
{
	VkVertexInputAttributeDescription input_attribute = {};
	m_vertexInputAttributes.push_back(input_attribute);
	m_createInfo.vertexAttributeDescriptionCount = m_vertexInputAttributes.size();
	m_createInfo.pVertexAttributeDescriptions = m_vertexInputAttributes.data();
	return &m_vertexInputAttributes.back();
}

VkVertexInputBindingDescription* VertexInputStateInfo::CreateBinding(uint32_t binding, uint32_t stride, VkVertexInputRate rate)
{
	VkVertexInputBindingDescription* input_binding = CreateBinding();
	input_binding->binding  = binding;
	input_binding->stride = stride;
	input_binding->inputRate = rate;
	return input_binding;
}

VkVertexInputAttributeDescription* VertexInputStateInfo::CreateAttribute(uint32_t location, uint32_t binding, VkFormat format, uint32_t offset)
{
	VkVertexInputAttributeDescription* input_attribute = CreateAttribute();
	input_attribute->location = location;
	input_attribute->binding = binding;
	input_attribute->format = format;
	input_attribute->offset = offset;
	return input_attribute;
}

} /* namespace VK */
