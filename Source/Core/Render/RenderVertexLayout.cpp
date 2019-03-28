/*
 * RenderVertexLayout.cpp
 *
 *  Created on: Mar 23, 2019
 *      Author: rookyma
 */

#include "RenderVertexLayout.h"
#include "RenderElement.h"
#include <cassert>

namespace Render
{

VertexLayout::VertexLayout(void)
{
}

VertexLayout::~VertexLayout(void)
{
	mElements.clear();
}

void VertexLayout::SetElement(const std::vector<Render::Element>& elements)
{
	assert(elements.size() > 0);
	assert(mElements.size() == 0);
	for (auto& element : elements)
	{
		mElements.push_back(element);
		ElementType type = element.GetType();
		mSizeInByte += Element::GetTypeSize(type);
	}
}

void VertexLayout::AppendElement(const Element& element)
{
	mElements.push_back(element);
	ElementType type = element.GetType();
	mSizeInByte += Element::GetTypeSize(type);
}

} /* namespace Render */
