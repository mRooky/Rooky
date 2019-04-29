/*
 * RenderPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "GHIPipelineLayout.h"
#include <cassert>

namespace GHI
{

PipelineLayout::PipelineLayout(Device* device):
		Object(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
}

void PipelineLayout::PushVertexLayout(const VertexLayout& layout)
{
	assert(this != nullptr);
	uint32_t binding = mInputLayout.GetVertexElementCount();
	mInputLayout.PushVertexLayout(binding, layout);
}

void PipelineLayout::PushVertexLayout(uint32_t binding, const VertexLayout& layout)
{
	assert(this != nullptr);
	mInputLayout.PushVertexLayout(binding, layout);
}

} /* namespace Render */
