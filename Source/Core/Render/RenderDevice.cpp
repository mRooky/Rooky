/*
 * RenderContext.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderDevice.h"
#include "RenderFactory.h"
#include "RenderQueue.h"
#include "UtilityRelease.h"

namespace Render
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
