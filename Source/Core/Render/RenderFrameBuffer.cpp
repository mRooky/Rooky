/*
 * RenderFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderFrameBuffer.h"

#include <algorithm>
#include <iostream>
#include <cassert>

namespace Render
{

FrameBuffer::FrameBuffer(Pass* pass):
		mPass(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
	mPass = nullptr;

}



} /* namespace Render */
