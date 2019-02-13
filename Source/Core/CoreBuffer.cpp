/*
 * CoreBuffer.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreBuffer.h"
#include <cassert>

namespace Core
{

Buffer::Buffer(BufferManager* creator):
		mCreator(creator)
{
	assert(mCreator != nullptr);
}

Buffer::~Buffer(void)
{
	mCreator = nullptr;
}

} /* namespace Core */
