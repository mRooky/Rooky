/*
 * CoreStorage.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreStorage.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

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
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
