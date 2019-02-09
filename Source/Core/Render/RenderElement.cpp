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
	mFormats.clear();
}

void Element::Create(const std::vector<Format>& formats)
{
	assert(formats.size() > 0);
	for (auto format : formats)
	{
		mFormats.push_back(format);
		mStride += GetFormatSize(format);
	}
	assert(mStride > 0);
}

} /* namespace Render */
