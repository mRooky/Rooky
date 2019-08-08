/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "GHIBindingLayout.h"
#include "GHIBindingSet.h"
#include <cassert>
#include <algorithm>

namespace GHI
{

BindingLayout::BindingLayout(void)
{
	mBindingSets.reserve(8);
}

BindingLayout::~BindingLayout(void)
{
	mBindingSets.clear();
}

void BindingLayout::AppendBindingSet(const BindingSet* set)
{
	assert(mBindingSets.size() < 8 - 1);
	assert(set->IsValid());
	mBindingSets.push_back(set);
}

void BindingLayout::PushBindingSet(size_t index, const BindingSet* set)
{
	assert(index < 8);
	assert(index < mBindingSets.size());
	if (true)
	{
		// Set Check
		assert(false);
	}
	mBindingSets.at(index) = set;
}

} /* namespace Render */
