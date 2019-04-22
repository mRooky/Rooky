/*
 * RenderFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "GHIFrameBuffer.h"
#include <algorithm>
#include <iostream>
#include <cassert>

namespace GHI
{

FrameBuffer::FrameBuffer(RenderPass* pass):
		mPass(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
	mPass = nullptr;

}



} /* namespace Render */
