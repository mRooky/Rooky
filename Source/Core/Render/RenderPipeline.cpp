/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"
#include "RenderShaderState.h"
#include "RenderPipelineCommon.h"
#include "RenderDevice.h"
#include "RenderFactory.h"

namespace Render
{

Pipeline::Pipeline(Device* device):
		Object(device)
{
}

Pipeline::~Pipeline(void)
{
	mPipelineState = nullptr;
}

} /* namespace Render */
