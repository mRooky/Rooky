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
	GHI::UsageType usage;
	usage.read = TRUE;
	usage.write = TRUE;
	usage.type = GHI::ResourceType::BUFFER;
	Create(type, count, usage);
}

void Index::Create(GHI::IndexType type, uint32_t count, GHI::UsageType usage)
{
	mType = type;
	mCount = count;
	size_t size = GHI::GetIndexTypeSize(mType) * mCount;
	assert(size > 0);
	usage.indexBuffer = TRUE;
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
