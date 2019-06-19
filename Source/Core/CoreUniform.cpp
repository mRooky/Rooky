/*
 * CoreUniform.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreUniform.h"

#include <cassert>

namespace Core
{

Uniform::Uniform(BufferManager* creator):
		Buffer(creator)
{
}

Uniform::~Uniform(void)
{
}

void Uniform::Create(size_t size, GHI::UsageType usage)
{
	assert(size > 0);
	mSize = size;
	usage.uniformBuffer = TRUE;
	usage.type = GHI::ResourceType::BUFFER;
	mHostMemory.Allocate(size);
	CreateRenderBuffer(mSize, usage);
}

} /* namespace Core */
