/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "RenderBindingSet.h"
#include "RenderResource.h"
#include "UtilSearch.h"
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
	auto old_usage = mBindings.at(index).GetResource()->GetUsage();
	auto new_usage = binding.GetResource()->GetUsage();
	assert(old_usage == new_usage);
	if (old_usage == new_usage)
	{
		mBindings.at(index) = binding;
	}
}

} /* namespace Render */
