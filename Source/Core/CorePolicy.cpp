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

namespace Core
{

Policy::Policy(void)
{
}

Policy::~Policy(void)
{
	delete mRenderPass;
	mRenderPass = nullptr;
	Utility::Release(mSubPolicies);
}

} /* namespace Core */
