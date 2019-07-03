/*
 * CoreIndex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreIndex.h"
#include "CoreSystem.h"
#include "GHI/GHIInline.h"

#include <iostream>

namespace Core
{

Index::Index(BufferManager* creator):
		Buffer(creator)
{
}

Index::~Index(void)
{
	mCount = 0;
	mType = GHI::IndexType::UNKNOWN;
}

void Index::Create(GHI::IndexType type, uint32_t count)
{
	GHI::ResourceUsage usage;
	usage.memoryUsage.read = TRUE;
	usage.memoryUsage.write = TRUE;
	Create(type, count, usage);
}

void Index::Create(GHI::IndexType type, uint32_t count, GHI::ResourceUsage& usage)
{
	mType = type;
	mCount = count;
	size_t size = GHI::GetIndexTypeSize(mType) * mCount;
	assert(size > 0);
	usage.bufferUsage.indexBuffer = TRUE;
	mHostMemory.Allocate(size);
	CreateRenderBuffer(size, usage);
	mDrawIndexed.SetIndexCount(mCount);
	std::cout << "Create Index Type : " << GHI::GetIndexTypeName(mType) << std::endl;
}

size_t Index::GetSizeInByte(void)
{
	const size_t size = GHI::GetIndexTypeSize(mType) * mCount;
	return size;
}

} /* namespace Core */
