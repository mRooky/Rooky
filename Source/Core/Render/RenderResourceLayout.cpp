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

void ResourceLayout::AppendResourceList(ResourceList* list)
{
	auto iterator = std::find(mResourceLists.begin(), mResourceLists.end(), list);
	if (iterator != mResourceLists.end())
	{
		assert(false);
	}
	else
	{
		mResourceLists.push_back(list);
	}
}

} /* namespace Render */
