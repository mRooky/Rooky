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
	bool valid = shaderList.IsValid();
	valid = valid && (pRenderPass != nullptr);
	valid = valid && (pDeclaration != nullptr);
	valid = valid && (pPipelineState != nullptr);
	valid = valid && (pPipelineLayout != nullptr);
	return valid;
}

bool PipelineDetail::operator == (const PipelineDetail& other) const
{
	bool equal = (index == other.index);
	equal = equal && (shaderList == other.shaderList);
	equal = equal && (pRenderPass == other.pRenderPass);
	equal = equal && (pDeclaration == other.pDeclaration);
	equal = equal && (pPipelineState == other.pPipelineState);
	equal = equal && (pPipelineLayout == other.pPipelineLayout);
	return equal;
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
