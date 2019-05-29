/*
 * VKImplement.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "VKDevice.h"
#include <cassert>

namespace GHI
{
Device* CreateDevice(void)
{
	return new VK::Device;
}

void DestroyDevice(Device* device)
{
	assert(device != nullptr);
	delete device;
}
}


