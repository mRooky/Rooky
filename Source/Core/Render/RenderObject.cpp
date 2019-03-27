/*
 * RenderObject.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderObject.h"
#include <cassert>

namespace Render
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
