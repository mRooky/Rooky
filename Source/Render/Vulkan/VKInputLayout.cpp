/*
 * Declaration.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */


#include "VKInputLayout.h"
#include "GHIInputLayout.h"
#include <cassert>
#include <iostream>

namespace VK
{

InputLayout::InputLayout(void)
{
}

InputLayout::~InputLayout(void)
{
}

void InputLayout::CreateInputState(const GHI::InputLayout* layout)
{
	assert(layout != nullptr);
	if (layout->IsValid())
	{
		const size_t binding_count = layout->GetVertexElementCount();
		for (size_t binding = 0; binding < binding_count; ++binding)
		{
			auto vertex_layout = layout->GetVertexLayout(binding);
			VkVertexInputBindingDescription* input_binding = mInputStateInfo.GetBinding(binding);
			input_binding->stride = vertex_layout.GetStride();

			uint32_t offset = 0;
			uint32_t attribute_count = vertex_layout.GetSemanticElementCount();
			for(uint32_t location = 0; location < attribute_count; ++location)
			{
				auto semantic = vertex_layout.GetSemanticElement(location);
				auto semantic_type = semantic.GetSemanticType();
				VkVertexInputAttributeDescription* input_attribute = mInputStateInfo.GetAttribute(binding, location);
				input_attribute->offset = offset;
				input_attribute->format = InputLayout::GetElementFormat(semantic_type);
				offset += GHI::GetTypeSize(semantic_type);
			}
		}
	}
}

VkFormat InputLayout::GetElementFormat(GHI::SemanticType type)
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
