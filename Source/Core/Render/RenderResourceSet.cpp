/*
 * RenderResourceSet.cpp
 *
 *  Created on: Feb 21, 2019
 *      Author: rookyma
 */

#include "RenderResourceSet.h"

namespace Render
{

ResourceSet::ResourceSet(void)
{
}

ResourceSet::~ResourceSet(void)
{
	ClearResource();
}

void ResourceSet::AppendResource(Resource* resource, ResourceType type)
{
	ResourceDesc desc = ResourceDesc(resource, type);
	mResourceDescs.push_back(desc);
}

} /* namespace Render */
