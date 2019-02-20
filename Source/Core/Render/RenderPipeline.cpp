/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"

namespace Render
{

Pipeline::Pipeline(PipelineState* state):
		mPipelineState(state)
{
}

Pipeline::~Pipeline(void)
{
}

} /* namespace Render */
