/*
 * CoreData.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */


#include "CoreHostMemory.h"
#include <cassert>
#include <cstring>

namespace Core
{

HostMemory::HostMemory(void)
{
}

HostMemory::~HostMemory(void)
{
	Free();
}

void HostMemory::Free(void)
{
	mSize = 0;
	delete[] mMemory;
	mMemory = nullptr;
}

void HostMemory::Allocate(size_t size)
{
	assert(size > 0);
	mSize = size;
	mMemory = new uint8_t[size];
}

bool HostMemory::Update(const uint8_t* src, size_t offset, size_t size)
{
	assert(mSize > 0 && mMemory != nullptr);
	if(size > 0)
	{
		bool contain = (offset + size) < mSize;
		if(contain)
		{
			uint8_t* dst = mMemory + offset;
			std::memcpy(dst, src, size);
			mDirtyRanges.push_back(RangeSize(offset, size));
			return true;
		}
	}
	return false;
}

RangeSize HostMemory::GetMergeRange(void) const
{
	RangeSize range = {};
	const size_t count = mDirtyRanges.size();
	if (count > 0)
	{
		range = mDirtyRanges.at(0);
		for (size_t index = 1; index < count; ++index)
		{
			const auto& element = mDirtyRanges.at(index);
			range.size = std::max(range.size, element.size);
			range.offset = std::min(range.offset, element.offset);
		}
	}
	return range;
}

}
