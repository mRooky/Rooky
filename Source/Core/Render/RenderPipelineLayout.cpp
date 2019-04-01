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

PipelineLayout::PipelineLayout(Device* device):
		Object(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
}

} /* namespace Render */
