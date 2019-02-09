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

} /* namespace Render */
