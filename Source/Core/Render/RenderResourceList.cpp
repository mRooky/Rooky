/*
 * RenderResourceSet.cpp
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#include "RenderResourceList.h"
#include <cassert>

namespace Render
{

ResourceList::ResourceList(void)
{
}

ResourceList::~ResourceList(void)
{
}

void ResourceList::SetBinding(uint32_t bind, const Binding& binding)
{
	assert(binding.IsValid());
	auto iterator = mResourceBindings.find(bind);
	if (iterator != mResourceBindings.end())
	{
		if (iterator->second != binding)
		{
			mDirty = true;
			iterator->second = binding;
		}
	}
	else
	{
		mDirty = true;
		mResourceBindings.insert(std::make_pair(bind, binding));
	}
}

} /* namespace Render */
