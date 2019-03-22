/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "RenderBindingState.h"
#include "UtilSearch.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingState::BindingState(BindingLayout* layout):
		mLayout(layout)
{
}

BindingState::~BindingState(void)
{
}

bool BindingState::operator==(const BindingState& other) const
{
	if (mBindingMask == other.mBindingMask)
	{
		const size_t count = mBindings.size();
		for (size_t index = 0; index < count; ++index)
		{
			if (mBindingMask.test(index))
			{
				auto& old_binding = mBindings.at(index);
				auto& new_binding = other.mBindings.at(index);
				if (old_binding != new_binding)
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

} /* namespace Render */
