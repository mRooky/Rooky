/*
 * RenderDeclaration.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "RenderElement.h"
#include <cassert>

namespace Render
{

Element::Element(Context* context):
		Object(context)
{
}

Element::~Element(void)
{
	mSemantics.clear();
}

void Element::AppendSemantic(Format semantic)
{
	mSemantics.push_back(semantic);
	mStride += GetFormatSize(semantic);
}

void Element::RemoveSemantic(size_t index)
{
	assert(index < mSemantics.size());
	auto iterator = mSemantics.begin();
	for (size_t i = 0; i < index; ++i)
	{
		++iterator;
	}
	mSemantics.erase(iterator);
	mStride -= GetFormatSize(*iterator);
}

} /* namespace Render */
