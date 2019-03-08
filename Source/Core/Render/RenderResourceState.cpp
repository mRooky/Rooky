/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "RenderResourceState.h"
#include <cassert>
#include <algorithm>

namespace Render
{

ResourceState::ResourceState(ResourceLayout* layout):
		mLayout(layout)
{
}

ResourceState::~ResourceState(void)
{
}

void ResourceState::AppendResource(const Resource& resource)
{
	assert(resource.IsValid());
	auto iterator = std::find(mResources.begin(), mResources.end(), resource);
	assert(iterator == mResources.end());
	if (iterator == mResources.end())
	{
		mResources.push_back(resource);
	}
}

} /* namespace Render */
