/*
 * RenderDeclaration.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "RenderDeclaration.h"

#include <cassert>

namespace Render
{

Declaration::Declaration(Context* context):
		Object(context)
{
}

Declaration::~Declaration(void)
{
	mFormats.clear();
}

uint32_t Declaration::GetStride(void) const
{
	uint32_t stride = 0;
	assert(false);
	return stride;
}

} /* namespace Render */
