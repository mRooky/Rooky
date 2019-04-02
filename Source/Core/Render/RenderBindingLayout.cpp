/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "UtilityRelease.h"
#include "RenderBindingLayout.h"
#include "RenderBindingSet.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingLayout::BindingLayout(void)
{
	mBindingSets.reserve(MAX_BINDING_PER_SET);
}

BindingLayout::~BindingLayout(void)
{
	mBindingSets.clear();
}

void BindingLayout::AppendBindingSet(const Render::BindingSet* set)
{
	assert(mBindingSets.size() < MAX_BINDING_PER_SET - 1);
	assert(set->IsValid());
	mBindingSets.push_back(set);
}

void BindingLayout::SetBindingSet(size_t index, const Render::BindingSet* set)
{
	assert(index < MAX_BINDING_PER_SET);
	assert(index < mBindingSets.size());
	if (true)
	{
		// Set Check
		assert(false);
	}
	mBindingSets.at(index) = set;
}

} /* namespace Render */
