/*
 * RenderResourceLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderBindingLayout.h"
#include "RenderPipelineLayout.h"
#include <cassert>
#include <algorithm>

namespace Render
{

BindingLayout::BindingLayout(Context* context):
		Object(context)
{
}

BindingLayout::~BindingLayout(void)
{
	delete mPipelineLayout;
	mPipelineLayout = nullptr;
}

} /* namespace Render */
