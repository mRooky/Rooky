/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"
#include <cassert>

namespace Render
{

Pipeline::Pipeline(PipelineState* state):
		mPipelineState(state)
{
	assert(mPipelineState != nullptr);
}

Pipeline::~Pipeline(void)
{
	mPipelineState = nullptr;
}

} /* namespace Render */
