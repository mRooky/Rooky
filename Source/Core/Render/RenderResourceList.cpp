/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "RenderResourceList.h"
#include <cassert>
#include <algorithm>

namespace Render
{

ResourceList::ResourceList(ResourceLayout* layout):
		mLayout(layout)
{
}

ResourceList::~ResourceList(void)
{
}

void ResourceList::AppendResource(const Resource& resource)
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
