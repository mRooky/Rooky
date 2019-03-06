/*
 * RenderPipelineDeteil.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "RenderPipelineDetail.h"

namespace Render
{

PipelineDetail::PipelineDetail(void)
{
}

PipelineDetail::~PipelineDetail(void)
{
}

bool PipelineDetail::IsValid(void) const
{
	bool valid = shaderList.IsValid()
			&& pRenderPass != nullptr
			&& pDeclaration != nullptr
			&& pPipelineState != nullptr
			&& pPipelineLayout != nullptr;
	return valid;
}

PipelineDetail& PipelineDetail::operator =(const PipelineDetail& other)
{
	index = other.index;
	shaderList = other.shaderList;
	pRenderPass = other.pRenderPass;
	pDeclaration = other.pDeclaration;
	pPipelineState = other.pPipelineState;
	pPipelineLayout = other.pPipelineLayout;
	return *this;
}

} /* namespace Render */
