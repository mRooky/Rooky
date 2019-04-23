/*
 * CoreSubPolicy.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "CoreSubPolicy.h"
#include "CorePolicy.h"

#include <cassert>

namespace Core
{

SubPolicy::SubPolicy(Policy* policy):
		mParentPolicy(policy)
{
	assert(mParentPolicy != nullptr);
}

SubPolicy::~SubPolicy(void)
{
	mParentPolicy = nullptr;
}

void SubPolicy::Create(size_t index)
{
	mIndex = index;
	CreatePipeline();
	CreateFrameBuffer();
}

void SubPolicy::CreatePipeline(void)
{

}

void SubPolicy::CreateFrameBuffer(void)
{
	assert(mRenderTargets.size() > 0);
}

} /* namespace Core */
