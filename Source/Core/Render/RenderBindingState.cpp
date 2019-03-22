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

} /* namespace Render */
