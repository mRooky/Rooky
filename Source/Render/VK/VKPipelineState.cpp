/*
 * VKPipelineState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */


#include "VKPipelineState.h"
#include "VKPipeline.h"
#include "VKDevice.h"

#include <cassert>

namespace VK
{

PipelineState::PipelineState(Device* device):
		Render::PipelineState(device)
{
}

PipelineState::~PipelineState(void)
{
}

void PipelineState::Initialize(void)
{
	assert(false);
}

}

