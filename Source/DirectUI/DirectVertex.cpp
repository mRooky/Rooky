/*
 * DirectVertex.cpp
 *
 *  Created on: Oct 12, 2018
 *      Author: rookyma
 */

#include "DirectVertex.h"
#include <VulkanFormat.h>
#include <cassert>

namespace Direct
{

Vertex::Vertex(void)
{
}

Vertex::~Vertex(void)
{
	static_assert(sizeof(Vertex) == 5 * sizeof(float), "Vertex size 5 * 4");
}

void Vertex::SetPosition(float x, float y)
{
	position[0] = x;
	position[1] = y;
}

void Vertex::SetTexCoord(float u, float v)
{
	texCoord[0] = u;
	texCoord[1] = v;
}

void Vertex::SetColor(float r, float g, float b, float a)
{
	color = ColorI(r, g, b, a);
}

VkVertexInputBindingDescription Vertex::GetInputBindingDescription(void)
{
	VkVertexInputBindingDescription input_binding_description = {};
	input_binding_description.stride = sizeof(Vertex);
	input_binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
	return input_binding_description;
}

std::vector<VkVertexInputAttributeDescription> Vertex::GetInputAttributeDescriptions(void)
{
	const static std::vector<VkFormat> elements =
	{
			VK_FORMAT_R32G32_SFLOAT,
			VK_FORMAT_R32G32_SFLOAT,
			VK_FORMAT_R32G32B32A32_SFLOAT
	};

	uint32_t offset = 0;
	std::vector<VkVertexInputAttributeDescription> vertex_input_attributes;
	for (size_t index = 0; index < elements.size(); ++index)
	{
		VkFormat format = elements.at(index);
		VkVertexInputAttributeDescription input_attribute_description = {};
		input_attribute_description.location = vertex_input_attributes.size();
		input_attribute_description.format = format;
		input_attribute_description.offset = offset;
		vertex_input_attributes.push_back(input_attribute_description);
		offset += Vulkan::Format::GetFormatSize(format);
	}

	assert(vertex_input_attributes.size() == 3);
	return vertex_input_attributes;
}

} /* namespace Direct */
