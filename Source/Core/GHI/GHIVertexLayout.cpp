/*
 * GHIVertexElement.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#include "GHIVertexLayout.h"

namespace GHI
{
	VertexElement* VertexLayout::GetVertexElementBinding(uint32_t binding)
	{
		for (auto& element : mVertexElements)
		{
			uint32_t element_binding = element.GetBinding();
			if (binding == element_binding)
			{
				return &element;
			}
		}

		VertexElement element;
		element.SetBinding(binding);
		mVertexElements.push_back(element);
		return &mVertexElements.back();
	}

	void VertexLayout::PushSemantic(uint32_t binding, const VertexElement& element)
	{
		VertexElement* exist = GetVertexElementBinding(binding);
		const size_t count = element.GetSemanticElementCount();
		for (size_t index = 0; index < count; ++index)
		{
			const auto& semantic = element.GetSemanticElement(index);
			exist->Push(semantic.semantic, semantic.type);
		}
	}

	void VertexLayout::PushSemantic(uint32_t binding, Semantic semantic, SemanticType type)
	{
		VertexElement* element = GetVertexElementBinding(binding);
		element->Push(semantic, type);
	}

	VertexLayout& VertexLayout::operator=(const VertexLayout& other)
	{
		mVertexElements = other.mVertexElements;
		return *this;
	}
}
