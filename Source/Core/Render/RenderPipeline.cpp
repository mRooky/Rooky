/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"
#include "RenderShaderState.h"
#include "RenderPipelineState.h"
#include "RenderDevice.h"
#include "RenderFactory.h"

namespace Render
{

Pipeline::Pipeline(Device* device):
		Object(device)
{
	mShaderState = new ShaderState;
	mPipelineState = mDevice->GetFactory()->CreatePipelineState();
}

Pipeline::~Pipeline(void)
{
	delete mShaderState;
	mShaderState = nullptr;
	delete mPipelineState;
	mPipelineState = nullptr;
}

} /* namespace Render */
