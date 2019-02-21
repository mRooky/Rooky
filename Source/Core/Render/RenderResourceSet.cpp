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

void ResourceSet::AppendResource(Object* object, ResourceType type)
{
	ResourceDesc desc = ResourceDesc(object, type);
	m_resourceDescs.push_back(desc);
}

} /* namespace Render */
