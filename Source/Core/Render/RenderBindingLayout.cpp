/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderBindingLayout.h"
#include "RenderBindingSet.h"
#include "RenderPipelineLayout.h"
#include "UtilRelease.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingLayout::BindingLayout(Device* device):
		Object(device)
{
	mBindingSets.reserve(MAX_BINDING_PER_SET);
}

BindingLayout::~BindingLayout(void)
{
	mBindingSets.clear();
	delete mPipelineLayout;
	mPipelineLayout = nullptr;
}

} /* namespace Render */
