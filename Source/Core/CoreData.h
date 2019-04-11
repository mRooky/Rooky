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
	Data(void);
	~Data(void);

public:
	void FreeMemory(void);
	void AllocateMemory(size_t size);

public:
	inline void* GetMemory(void) const { return mMemory; }

public:
	inline bool IsValid(void) const { return mMemory != nullptr; }

protected:
	size_t mSize = 0;
	uint8_t* mMemory = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREDATA_H_ */
