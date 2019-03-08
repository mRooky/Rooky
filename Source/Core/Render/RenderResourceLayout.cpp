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

void ResourceLayout::AppendResourceState(ResourceState* state)
{
	auto iterator = std::find(mResourceStates.begin(), mResourceStates.end(), state);
	if (iterator != mResourceStates.end())
	{
		assert(false);
	}
	else
	{
		mResourceStates.push_back(state);
	}
}

} /* namespace Render */
