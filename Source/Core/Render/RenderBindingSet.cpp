/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "UtilitySearch.h"
#include "RenderBindingSet.h"
#include "RenderResource.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingSet::BindingSet(Device* device):
		Object(device)
{
}

BindingSet::~BindingSet(void)
{
}

void BindingSet::SetBinding(uint32_t index, const Binding& binding)
{
	assert(index < mBindings.size());
	Render::Resource* new_resource = binding.GetResource();
	Render::Resource* old_resource = mBindings.at(index).GetResource();
	auto old_usage = old_resource->GetUsage();
	auto new_usage = new_resource->GetUsage();
	assert(old_usage == new_usage);
	if (old_usage == new_usage)
	{
		mBindings.at(index) = binding;
	}
}

} /* namespace Render */
