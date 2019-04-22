/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "GHIBindingSet.h"
#include "GHIResource.h"
#include <cassert>
#include "UtilitySearch.h"

namespace GHI
{

BindingSet::BindingSet(Device* device):
		Object(device)
{
}

BindingSet::~BindingSet(void)
{
}

void BindingSet::AppendBinding(const Binding& binding)
{
	auto iterator = Utility::Find(mBindings, binding);
	if (iterator == mBindings.end())
	{
		mBindings.push_back(binding);
	}
}

void BindingSet::SetBinding(uint32_t index, const Binding& binding)
{
	assert(index < mBindings.size());
	GHI::Resource* new_resource = binding.GetResource();
	GHI::Resource* old_resource = mBindings.at(index).GetResource();
	assert(old_resource->GetUsage() == new_resource->GetUsage());
	if (old_resource->GetUsage() == new_resource->GetUsage())
	{
		mBindings.at(index) = binding;
	}
}

} /* namespace Render */
