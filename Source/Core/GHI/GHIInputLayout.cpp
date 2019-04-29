/*
 * GHIVertexElement.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#include "GHIInputLayout.h"
#include <cassert>

namespace GHI
{
	VertexLayout* InputLayout::GetVertexLayoutBinding(uint32_t binding)
	{
		if (binding == mVertexLayouts.size())
		{
			VertexLayout layout;
			mVertexLayouts.push_back(layout);
		}
		return &mVertexLayouts.at(binding);
	}

	void InputLayout::PushVertexLayout(uint32_t binding, const VertexLayout& layout)
	{
		VertexLayout* exist = GetVertexLayoutBinding(binding);
		const size_t count = layout.GetSemanticCount();
		for (size_t index = 0; index < count; ++index)
		{
			const auto& semantic = layout.GetSemantic(index);
			exist->PushSemantic(semantic.semantic, semantic.type);
		}
	}

	void InputLayout::PushVertexLayout(uint32_t binding, Semantic semantic, SemanticType type)
	{
		VertexLayout* layout = GetVertexLayoutBinding(binding);
		layout->PushSemantic(semantic, type);
	}
}
