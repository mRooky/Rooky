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
#include "RenderEnum.h"

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
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_UNIFORM;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, access);
}

} /* namespace Core */
