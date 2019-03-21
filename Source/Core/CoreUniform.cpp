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

void Uniform::Create(size_t size, Render::AllocateType allocate)
{
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.UniformBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
