/*
 * Declaration.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "VKVertexLayout.h"
#include <cassert>

namespace VK
{

VertexLayout::VertexLayout(void)
{
}

VertexLayout::~VertexLayout(void)
{
}

void VertexLayout::CreateInputState(void)
{
	assert(mElements.size() > 0);
	uint32_t offset = 0;
	for (auto& element : mElements)
	{
		uint32_t binding = element.GetBinding();
		auto type = element.GetType();
		VkVertexInputBindingDescription* input_binding = mInputStateInfo.GetBinding(binding);
		input_binding->stride += Render::Element::GetTypeSize(type);

		uint32_t location = element.GetLocation();
		VkVertexInputAttributeDescription* input_attribute = mInputStateInfo.GetAttribute(binding, location);
		input_attribute->offset = offset;
		input_attribute->format = VertexLayout::GetElementFormat(type);
	}
}

VkFormat VertexLayout::GetElementFormat(Render::ElementType type)
{
	switch(type)
	{
	case Render::ElementType::ELEMENT_TYPE_FLOAT1:
		return VK_FORMAT_R32_SFLOAT;
	case Render::ElementType::ELEMENT_TYPE_FLOAT2:
		return VK_FORMAT_R32G32_SFLOAT;
	case Render::ElementType::ELEMENT_TYPE_FLOAT3:
		return VK_FORMAT_R32G32B32_SFLOAT;
	case Render::ElementType::ELEMENT_TYPE_FLOAT4:
		return VK_FORMAT_R32G32B32A32_SFLOAT;
	default:
		assert(false);
	}
	return VK_FORMAT_UNDEFINED;
}

} /* namespace VK */
