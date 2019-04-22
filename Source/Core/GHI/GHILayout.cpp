/*
 * RenderLayout.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#include "GHILayout.h"
#include <cassert>
namespace GHI
{
void VertexLayout::SetElement(const std::vector<GHI::Element>& elements)
{
	assert(elements.size() > 0);
	assert(mElements.size() == 0);
	for (auto& element : elements)
	{
		mElements.push_back(element);
		ElementType type = element.GetType();
		mStride += Element::GetTypeSize(type);
	}
}

void VertexLayout::AppendElement(const Element& element)
{
	mElements.push_back(element);
	ElementType type = element.GetType();
	mStride += Element::GetTypeSize(type);
}
}
