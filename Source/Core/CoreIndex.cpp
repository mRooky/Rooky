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
#include "RenderUtility.h"

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
	Render::BufferUsage usage = {};
	usage.BufferUsageIndex = 1;
	Buffer::Create(size, usage.BufferUsageFlags, access);
}

} /* namespace Core */
