/*
 * VKResourceSet.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "VKResourceSet.h"
#include <cassert>

namespace VK
{

ResourceSet::ResourceSet(void)
{
}

ResourceSet::~ResourceSet(void)
{
	mDescriptorSet = nullptr;
}

void ResourceSet::Binding(CommandList* list)
{
	UpdateDescriptorSet();
	assert(false);
}

void ResourceSet::UpdateDescriptorSet(void)
{
	assert(false);
}

} /* namespace VK */
