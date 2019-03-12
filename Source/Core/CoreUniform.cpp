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

void Uniform::Create(size_t size, Render::ResourceHeap heap)
{
	assert(size > 0);
	auto buffer_usage = Render::GetBufferUsage(true);
	buffer_usage.heap = heap;
	buffer_usage.binding.UniformBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
