/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIPipeline.h"
#include "GHIShaderState.h"

namespace GHI
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
