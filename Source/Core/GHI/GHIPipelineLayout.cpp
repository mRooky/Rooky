/*
 * RenderPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "GHIPipelineLayout.h"
#include <cassert>

namespace GHI
{

PipelineLayout::PipelineLayout(Device* device):
		Object(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
}

} /* namespace Render */
