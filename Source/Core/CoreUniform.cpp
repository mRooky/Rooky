/*
 * CoreUniform.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreUniform.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderContext.h"
#include "RenderUsage.h"

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

void Uniform::Create(size_t size, Render::HeapAccess access)
{
	assert(size > 0);
	Render::BufferUsage usage = {};
	usage.BufferUsageUniform = 1;
	Buffer::Create(size, usage.BufferUsageFlags, access);
}

} /* namespace Core */
