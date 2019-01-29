/*
 * RenderFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderFrameBuffer.h"

namespace Render
{

FrameBuffer::FrameBuffer(Pass* pass):
		mPass(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
}

} /* namespace Render */
