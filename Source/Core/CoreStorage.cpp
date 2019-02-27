/*
 * CoreStorage.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "CoreStorage.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderContext.h"
#include "RenderUsage.h"

#include <cassert>

namespace Core
{

Storage::Storage(BufferManager* creator):
		Buffer(creator)
{
}

Storage::~Storage(void)
{
}

void Storage::Create(size_t size)
{
	assert(size > 0);
	Render::BufferUsage usage = {};
	usage.BufferUsageCommon = 1;
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	Buffer::Create(size, usage.BufferUsageFlags, access);
}

} /* namespace Core */
