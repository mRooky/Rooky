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
	mMemory.Free();
}

void HostMemory::Allocate(size_t size)
{
	assert(size > 0);
	mMemory.Free();
	mMemory.Allocate(size);
}

bool HostMemory::Update(const uint8_t* src, size_t offset, size_t size)
{
	assert(mMemory.IsValid());
	if(size > 0)
	{
		uint8_t* dest = mMemory.Map(offset, size);
		assert(dest != nullptr);
		std::memcpy(dest, src, size);
		mDirtyRanges.push_back(RangeSize(offset, size));
		return true;
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

const void* HostMemory::GetMemoryRange(size_t index) const
{
	const auto& range = mDirtyRanges.at(index);
	return mMemory.Map(range.offset, range.size);
}

const void* HostMemory::GetMemoryRange(size_t offset, size_t size) const
{
	return mMemory.Map(offset, size);
}

}
