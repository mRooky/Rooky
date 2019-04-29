/*
 * Declaration.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "VKVertexLayout.h"
#include "GHIVertexLayout.h"

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

void VertexLayout::CreateInputState(const GHI::VertexLayout* layout)
{
	assert(layout != nullptr);
	if (layout->IsValid())
	{
		const size_t binding_count = layout->GetVertexElementCount();
		for (size_t binding = 0; binding < binding_count; ++binding)
		{
			auto element = layout->GetVertexElement(binding);
			VkVertexInputBindingDescription* input_binding = mInputStateInfo.GetBinding(binding);
			input_binding->stride = element.GetStride();

			uint32_t offset = 0;
			uint32_t attribute_count = element.GetSemanticElementCount();
			for(uint32_t location = 0; location < attribute_count; ++location)
			{
				auto semantic = element.GetSemanticElement(location);
				auto semantic_type = semantic.GetSemanticType();
				VkVertexInputAttributeDescription* input_attribute = mInputStateInfo.GetAttribute(binding, location);
				input_attribute->offset = offset;
				input_attribute->format = VertexLayout::GetElementFormat(semantic_type);
				offset += GHI::GetTypeSize(semantic_type);
			}
		}
	}
}

VkFormat VertexLayout::GetElementFormat(GHI::SemanticType type)
{
	switch(type)
	{
	case GHI::SemanticType::FLOAT1:
		return VK_FORMAT_R32_SFLOAT;
	case GHI::SemanticType::FLOAT2:
		return VK_FORMAT_R32G32_SFLOAT;
	case GHI::SemanticType::FLOAT3:
		return VK_FORMAT_R32G32B32_SFLOAT;
	case GHI::SemanticType::FLOAT4:
		return VK_FORMAT_R32G32B32A32_SFLOAT;
	default:
		assert(false);
	}
	return VK_FORMAT_UNDEFINED;
}

} /* namespace VK */
