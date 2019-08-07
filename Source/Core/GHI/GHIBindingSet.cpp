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
	mBindings.push_back(binding);
}

void BindingSet::SetBinding(uint32_t index, const Binding& binding)
{
	assert(index < mBindings.size());
	mBindings.at(index) = binding;
}

} /* namespace Render */
