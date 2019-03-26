/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"
#include "RenderShaderState.h"
#include "RenderPipelineState.h"

namespace Render
{

Pipeline::Pipeline(Context* context):
		Object(context)
{
	mShaderState = new ShaderState;
}

Pipeline::~Pipeline(void)
{
	delete mShaderState;
	mShaderState = nullptr;
	delete mPipelineState;
	mPipelineState = nullptr;
}

} /* namespace Render */
