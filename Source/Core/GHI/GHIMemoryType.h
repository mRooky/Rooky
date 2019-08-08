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
	MemoryType(void) = default;
	~MemoryType(void) = default;

public:
	inline bool CPUAccessable(void) const
	{
		return cpuAccess == TRUE;
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
