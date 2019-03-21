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

void Index::Create(Render::IndexType type, uint32_t count, Render::AllocateType allocate)
{
	mType = type;
	mCount = count;
	size_t size = Render::GetIndexTypeSize(type);
	size *= count;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.IndexBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
