/*
 * CorePipelineState.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#include "GHIPipelineState.h"

namespace GHI
{

PipelineState::PipelineState(void)
{
}

PipelineState::~PipelineState(void)
{
}

void PipelineState::PushVertexElement(uint32_t binding, VertexElement* element)
{
	mVertexLayout.PushSemantic(binding, *element);
}

bool PipelineState::operator==(const PipelineState& other) const
{
	bool equal = mIndex == other.mIndex
	&& mRenderPass == other.mRenderPass
	&& mVertexLayout == other.mVertexLayout
	&& mPipelineLayout == other.mPipelineLayout;
	if (equal)
	{
		equal = mBlendState == other.mBlendState
			&& mShaderState == other.mShaderState
			&& mMultisample == other.mMultisample
			&& mInputAssembly == other.mInputAssembly
			&& mRasterization == other.mRasterization;

		if (equal)
		{
			return mBlendState == other.mBlendState;
		}
	}
	return false;
}

} /* namespace Core */
