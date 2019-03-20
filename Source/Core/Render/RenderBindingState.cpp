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

void BindingState::AppendResource(const Binding& binding)
{
	assert(binding.IsValid());
	auto iterator = Util::Find(mBindings, binding);
	assert(iterator == mBindings.end());
	if (iterator == mBindings.end())
	{
		mBindings.push_back(binding);
	}
}

} /* namespace Render */
