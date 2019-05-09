/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "GHIBindingSet.h"
#include "GHIResource.h"
#include <cassert>

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
	bool exist = mBindings.FindElement(binding);
	if (!exist)
	{
		mBindings.PushElement(binding);
	}
}

void BindingSet::SetBinding(uint32_t index, const Binding& binding)
{
	assert(index < mBindings.GetElementCount());
	GHI::Resource* new_resource = binding.GetResource();
	const GHI::Binding& old_binding = mBindings.GetElementAt(index);
	GHI::Resource* old_resource = old_binding.GetResource();
	assert(old_resource->GetUsage() == new_resource->GetUsage());
	if (old_resource->GetUsage() == new_resource->GetUsage())
	{
		mBindings.SetElement(index, binding);
	}
}

} /* namespace Render */
