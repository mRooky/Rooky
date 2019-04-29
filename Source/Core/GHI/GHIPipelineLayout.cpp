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

void PipelineLayout::PushVertexElement(const VertexElement& element)
{
	assert(this != nullptr);
	uint32_t binding = mVertexLayout.GetVertexElementCount();
	mVertexLayout.PushSemantic(binding, element);
}

void PipelineLayout::PushVertexElement(uint32_t binding, const VertexElement& element)
{
	assert(this != nullptr);
	mVertexLayout.PushSemantic(binding, element);
}

} /* namespace Render */
