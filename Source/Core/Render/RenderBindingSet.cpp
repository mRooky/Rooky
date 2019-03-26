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

BindingSet::BindingSet(BindingLayout* layout):
		mLayout(layout)
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

bool BindingSet::operator==(const BindingSet& other) const
{
	assert(mBindings.size() > 0);
	if (mBindings.size() != other.mBindings.size())
	{
		return false;
	}
	const size_t count = mBindings.size();
	for (size_t index = 0; index < count; ++index)
	{
		auto& old_binding = mBindings.at(index);
		auto& new_binding = other.mBindings.at(index);
		if(old_binding != new_binding)
		{
			return false;
		}
	}
	return true;
}

} /* namespace Render */
