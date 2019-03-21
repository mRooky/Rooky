/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderBindingLayout.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingLayout::BindingLayout(Context* context):
		Object(context)
{
}

BindingLayout::~BindingLayout(void)
{
}

void BindingLayout::SetBindingState(uint32_t index, BindingState* state)
{
	assert(index < 8);
	mResourceMask.set(index);
	mBindingStates.at(index) = state;
}

} /* namespace Render */
