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
#include "RenderEnum.h"

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
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_COMMON;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	Buffer::Create(size, flags, access);
}

} /* namespace Core */
