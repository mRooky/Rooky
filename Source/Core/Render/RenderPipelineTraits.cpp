/*
 * RenderPipelineDeteil.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderPipelineTraits.h"

namespace Render
{

PipelineTraits::PipelineTraits(void)
{
}

PipelineTraits::~PipelineTraits(void)
{
}

bool PipelineTraits::IsValid(void) const
{
	bool valid = shaderState.IsValid();
	valid = valid && (pRenderPass != nullptr);
	valid = valid && (pPipelineState != nullptr);
	valid = valid && (pPipelineLayout != nullptr);
	return valid;
}

bool PipelineTraits::operator == (const PipelineTraits& other) const
{
	bool equal = (index == other.index);
	equal = equal && (shaderState == other.shaderState);
	equal = equal && (pRenderPass == other.pRenderPass);
	equal = equal && (pPipelineState == other.pPipelineState);
	equal = equal && (pPipelineLayout == other.pPipelineLayout);
	return equal;
}

PipelineTraits& PipelineTraits::operator =(const PipelineTraits& other)
{
	index = other.index;
	shaderState = other.shaderState;
	pRenderPass = other.pRenderPass;
	pPipelineState = other.pPipelineState;
	pPipelineLayout = other.pPipelineLayout;
	return *this;
}

} /* namespace Render */
