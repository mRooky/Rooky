/*
 * CoreData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREDATA_H_
#define SOURCE_CORE_COREDATA_H_

#include "Math/MathRange.h"
#include <cstdint>
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
	void Free(void);
	void Allocate(size_t size);

public:
	bool Update(const uint8_t* src, size_t offset, size_t size);

public:
	inline bool IsValid(void) const { return mMemory != nullptr; }

public:
	inline void ClearDirty(void) { mDirtyRanges.clear(); }
	inline size_t GetDirtyCount(void) const { return mDirtyRanges.size(); }

public:
	inline const RangeSize& GetDirtyRange(size_t index) const { return mDirtyRanges.at(index); }
	inline const uint8_t* GetOffsetMemory(size_t index) const { return mMemory + mDirtyRanges.at(index).offset; }

protected:
	size_t mSize = 0;
	uint8_t* mMemory = nullptr;

protected:
	std::vector<RangeSize> mDirtyRanges;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREDATA_H_ */
