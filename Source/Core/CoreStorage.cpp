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
	Render::ResourceUsage buffer_usage = Render::GetBufferUsage(true);
	buffer_usage.binding.StorageBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
