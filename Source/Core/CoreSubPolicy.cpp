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
		mParent(policy)
{
	assert(mParent != nullptr);
}

SubPolicy::~SubPolicy(void)
{
	mParent = nullptr;
}

void SubPolicy::Create(size_t index)
{
	mIndex = index;
	CreatePipeline();
	CreateFrameBuffer();
}

void SubPolicy::Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables)
{

}

void SubPolicy::CreatePipeline(void)
{

}

void SubPolicy::CreateFrameBuffer(void)
{
	assert(mRenderTargets.size() > 0);
}

} /* namespace Core */
