/*
 * CorePipelineState.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#include "RenderPipelineState.h"

namespace Render
{

PipelineState::PipelineState(void)
{
}

PipelineState::~PipelineState(void)
{
}

bool PipelineState::operator==(const PipelineState& other) const
{
	return mIndex == other.mIndex
	&& mRenderPass == other.mRenderPass
	&& mShaderState == other.mShaderState
	&& mVertexLayout == other.mVertexLayout
	&& mPipelineLayout == other.mPipelineLayout
	&& mPipelineCommon == other.mPipelineCommon
	&& mRenderBlendState == other.mRenderBlendState;
}

} /* namespace Core */
