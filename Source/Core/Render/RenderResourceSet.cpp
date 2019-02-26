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
}

void ResourceSet::AppendResource(Resource* resource, ResourceType type)
{
	ResourceDesc desc = ResourceDesc(resource, type);
	m_resourceDescs.push_back(desc);
}

} /* namespace Render */
