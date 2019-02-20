/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKContext.h"
#include "VKPipelineState.h"

#include "VulkanPipeline.h"
#include "VulkanInline.h"

#include <cassert>

namespace VK
{

Pipeline::Pipeline(PipelineState* state):
		Render::Pipeline(state)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(mPipeline);
}

void Pipeline::Initialize(Render::Pass* pass, uint32_t index)
{
	assert(false);
}

} /* namespace VK */
