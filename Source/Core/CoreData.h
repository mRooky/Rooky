/*
 * CoreData.h
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREDATA_H_
#define SOURCE_CORE_COREDATA_H_

#include <cstddef>
#include <cstdint>

namespace Core
{

class Data
{
public:
	Data(void) = default;
	~Data(void) { FreeBuffer(); }

public:
	inline void Allocate(size_t size)
	{
		mSize = size;
		mData = new uint8_t[size];
	}

	inline void FreeBuffer(void)
	{
		mSize = 0;
		delete[] mData;
		mData = nullptr;
	}

public:
	inline void* GetBuffer(void) const { return mData; }

public:
	inline bool IsValid(void) const { return mData != nullptr; }

protected:
	size_t mSize = 0;
	uint8_t* mData = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREDATA_H_ */
