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

PipelineLayout::PipelineLayout(ResourceLayout* layout):
		mResourceLayout(layout)
{
}

PipelineLayout::~PipelineLayout(void)
{
}

} /* namespace Render */
