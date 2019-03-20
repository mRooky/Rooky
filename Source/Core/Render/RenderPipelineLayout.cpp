/*
 * RenderPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderPipelineLayout.h"
#include <cassert>

namespace Render
{

PipelineLayout::PipelineLayout(BindingLayout* layout):
		mBindingLayout(layout)
{
}

PipelineLayout::~PipelineLayout(void)
{
}

} /* namespace Render */
