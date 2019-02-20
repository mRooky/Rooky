/*
 * VKPipelineState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */


#include "VKPipelineState.h"
#include "VKContext.h"
#include "VKPipeline.h"

#include <cassert>

namespace VK
{

PipelineState::PipelineState(Context* context):
		Render::PipelineState(context)
{
}

PipelineState::~PipelineState(void)
{
}

void PipelineState::CreateCache(void)
{
	assert(false);
}

void PipelineState::CreateLayout(void)
{
	assert(false);
}

}

