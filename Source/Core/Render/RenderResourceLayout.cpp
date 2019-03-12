/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderResourceLayout.h"
#include <cassert>
#include <algorithm>

namespace Render
{

ResourceLayout::ResourceLayout(Context* context):
		Object(context)
{
}

ResourceLayout::~ResourceLayout(void)
{
}

void ResourceLayout::SetResourceState(uint32_t index, ResourceState* state)
{
	assert(index < 8);
	mResourceMask.set(index);
	mResourceStates.at(index) = state;
}

} /* namespace Render */
