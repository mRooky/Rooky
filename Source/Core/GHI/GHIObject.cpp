/*
 * RenderObject.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "GHIObject.h"
#include <cassert>

namespace GHI
{

Object::Object(Device* device):
		mDevice(device)
{
	assert(mDevice != nullptr);
}

Object::~Object(void)
{
	mDevice = nullptr;
}

} /* namespace Render */
