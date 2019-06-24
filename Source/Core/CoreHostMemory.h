/*
 * CoreData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREDATA_H_
#define SOURCE_CORE_COREDATA_H_

#include "Kernel/KernelMemory.h"
#include "Math/MathRange.h"
#include <vector>

namespace Core
{

typedef Math::Range_t<size_t> RangeSize;

class HostMemory
{
public:
	HostMemory(void);
	~HostMemory(void);

public:
	void Allocate(size_t size);

public:
	bool Update(const uint8_t* src, size_t offset, size_t size);
	RangeSize GetMergeRange(void) const;
	const void* GetMemoryRange(size_t index) const;
	const void* GetMemoryRange(size_t offset, size_t size) const;

public:
	inline void ClearDirtyRange(void) { mDirtyRanges.clear(); }
	inline size_t GetDirtyCount(void) const { return mDirtyRanges.size(); }

public:
	inline const RangeSize& GetDirtyRange(size_t index) const { return mDirtyRanges.at(index); }

protected:
	Kernel::Memory mMemory = {};

protected:
	std::vector<RangeSize> mDirtyRanges;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREDATA_H_ */
