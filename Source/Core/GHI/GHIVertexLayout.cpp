/*
 * GHIVertexElement.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#include "GHIVertexLayout.h"
#include <cassert>

namespace GHI
{
	VertexElement* VertexLayout::GetVertexElementBinding(uint32_t binding)
	{
		if (binding == mVertexElements.size())
		{
			VertexElement element;
			mVertexElements.push_back(element);
			return &mVertexElements.back();
		}
		return &mVertexElements.at(binding);
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
