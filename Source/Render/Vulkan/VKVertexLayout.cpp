/*
 * Declaration.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "GHILayout.h"
#include "VKVertexLayout.h"

#include <cassert>
#include <iostream>

namespace VK
{

VertexLayout::VertexLayout(void)
{
}

VertexLayout::~VertexLayout(void)
{
}

void VertexLayout::CreateInputState(GHI::VertexLayout* layout)
{
	assert(layout != nullptr);
	if (layout->IsValid())
	{
		uint32_t offset = 0;
		const size_t count = layout->GetElementCount();
		for (size_t index = 0; index < count; ++index)
		{
			auto element = layout->GetElement(index);
			uint32_t binding = element.GetBinding();
			auto type = element.GetType();
			VkVertexInputBindingDescription* input_binding = mInputStateInfo.GetBinding(binding);
			input_binding->stride += GHI::Element::GetTypeSize(type);

			uint32_t location = element.GetLocation();
			VkVertexInputAttributeDescription* input_attribute = mInputStateInfo.GetAttribute(binding, location);
			input_attribute->offset = offset;
			input_attribute->format = VertexLayout::GetElementFormat(type);

			offset += GHI::Element::GetTypeSize(type);
		}
	}
}

VkFormat VertexLayout::GetElementFormat(GHI::ElementType type)
{
	switch(type)
	{
	case GHI::ElementType::ELEMENT_TYPE_FLOAT1:
		return VK_FORMAT_R32_SFLOAT;
	case GHI::ElementType::ELEMENT_TYPE_FLOAT2:
		return VK_FORMAT_R32G32_SFLOAT;
	case GHI::ElementType::ELEMENT_TYPE_FLOAT3:
		return VK_FORMAT_R32G32B32_SFLOAT;
	case GHI::ElementType::ELEMENT_TYPE_FLOAT4:
		return VK_FORMAT_R32G32B32A32_SFLOAT;
	default:
		assert(false);
	}
	return VK_FORMAT_UNDEFINED;
}

} /* namespace VK */
