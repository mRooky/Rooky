/*
 * RenderPipeline.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPipeline.h"

namespace Render
{

Pipeline::Pipeline(Pass* pass):
		mRenderPass(pass)
{
}

Pipeline::~Pipeline(void)
{
}

} /* namespace Render */
