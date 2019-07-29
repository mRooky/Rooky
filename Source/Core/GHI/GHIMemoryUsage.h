/*
 * =====================================================================================
 *
 *       Filename:  GHIMemoryUsage.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_MEMORY_H
#define SOURCE_CORE_GHI_MEMORY_H

#include "GHIDefine.h"

namespace GHI
{

class MemoryUsage
{
public:
	MemoryUsage(void) {}
	~MemoryUsage(void) {}

public:
	inline bool CPUAccessable(void) const { return cpuAccess == TRUE; }
	inline bool operator==(const MemoryUsage& other) const { return allFlags == other.allFlags; }

public:
	union
	{
		struct
		{
			uint8_t cpuAccess  : 1;
			uint8_t read       : 1;
			uint8_t write      : 1;
			uint8_t reserved   : 5;
		};
		uint8_t allFlags = 0;
	};
};

}

#endif
