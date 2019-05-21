/*
 * RenderContext.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIQueue.h"
#include "../Utility/UtilityRelease.h"

namespace GHI
{

Device::Device(void)
{
}

Device::~Device(void)
{
	delete mFactory;
	mFactory = nullptr;
	Utility::Release(mQueues);
}

} /* namespace Render */
