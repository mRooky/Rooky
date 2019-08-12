/*
 * =====================================================================================
 *
 *       Filename:  GHIMemoryType.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_MEMORY_TYPE_H
#define SOURCE_CORE_GHI_MEMORY_TYPE_H

#include "GHIDefine.h"

namespace GHI
{

class MemoryType
{
public:
	MemoryType(void) {};
	~MemoryType(void) {};

public:
	inline bool CPUAccessable(void) const
	{
		return cpuAccess == TRUE;
	}

	inline MemoryType& operator=(const MemoryType& other)
	{
		if (this != & other)
		{
			memoryFlags = other.memoryFlags;
		}
		return *this;
	}

	inline bool operator==(const MemoryType& other) const
	{
		return memoryFlags == other.memoryFlags;
	}

public:
	union
	{
		uint8_t memoryFlags = 0;
		struct
		{
			uint8_t cpuAccess  : 1;
			uint8_t read       : 1;
			uint8_t write      : 1;
			uint8_t reserved   : 5;
		};
	};

};

}

#endif
