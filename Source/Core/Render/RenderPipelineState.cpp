/*
 * CorePipelineState.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#include "RenderPipelineState.h"

namespace Render
{

PipelineState::PipelineState(Device* device):
		Object(device)
{
}

PipelineState::~PipelineState(void)
{
}

bool PipelineState::operator==(const PipelineState& other) const
{

	return true;
}

} /* namespace Core */
