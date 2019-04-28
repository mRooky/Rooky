/*
 * CorePolicy.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "CorePolicy.h"
#include "CoreSubPolicy.h"
#include "UtilityRelease.h"

#include "GHIRenderPass.h"
#include "GHICommandList.h"

#include <cassert>

namespace Core
{

Policy::Policy(PolicyType type):
		mType(type)
{
}

Policy::~Policy(void)
{
	delete mRenderPass;
	mRenderPass = nullptr;
	Utility::Release(mSubPolicies);
}

void Policy::Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables)
{
	assert(command->IsBegin());
}

} /* namespace Core */
