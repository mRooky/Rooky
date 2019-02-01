/*
 * RenderBuffer.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderBuffer.h"
#include <cassert>

namespace Render
{

Buffer::Buffer(BufferManager* manager):
		mManager(manager)
{
	assert(mManager != nullptr);
}

Buffer::~Buffer(void)
{
}

} /* namespace Render */
