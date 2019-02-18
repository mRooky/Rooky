/*
 * CoreIndex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreIndex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderElement.h"
#include "RenderContext.h"
#include "RenderBuffer.h"
#include "RenderInline.h"

namespace Core
{

Index::Index(BufferManager* creator):
		Buffer(creator)
{
}

Index::~Index(void)
{
	mCount = 0;
	mType = Render::IndexType::INDEX_TYPE_UNKNOWN;
}

void Index::Create(Render::IndexType type, uint32_t count, Render::HeapAccess access)
{
	mType = type;
	mCount = count;

	size_t size = Render::GetIndexTypeSize(type) * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_INDEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, access);
}

} /* namespace Core */
