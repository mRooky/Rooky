/*
 * CoreStorage.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "CoreStorage.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderTypes.h"
#include "RenderContext.h"

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
	auto usage = Render::BufferUsage::BUFFER_USAGE_COMMON;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, true);
}

} /* namespace Core */
