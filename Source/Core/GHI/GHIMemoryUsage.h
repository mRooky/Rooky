/*
 * =====================================================================================
 *
 *       Filename:  GHIMemoryUsage.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_MEMORY_H
#define SOURCE_CORE_GHI_MEMORY_H

#include "GHIImageUsage.h"
#include "GHIBufferUsage.h"
#include "GHIMemoryType.h"

namespace GHI
{

class MemoryUsage
{
public:
	MemoryUsage(void) {}
	~MemoryUsage(void) {}

public:
	inline bool CPUAccessable(void) const
	{
		return cpuAccess == TRUE;
	}

	inline const ImageUsage& GetImageUsage(void)
	{
		return imageUsage;
	}

	inline const BufferUsage& GetBufferUsage(void)
	{
		return bufferUsage;
	}

public:
	inline MemoryUsage& operator=(const ImageUsage& usage)
	{
		imageUsage = usage;
		return *this;
	}

	inline MemoryUsage& operator=(const BufferUsage& usage)
	{
		bufferUsage = usage;
		return *this;
	}

public:
	inline bool operator==(const MemoryUsage& other) const
	{
		return memoryFlags == other.memoryFlags
			&& resourceFlags == other.resourceFlags;
	}

public:
	union
	{
		uint8_t resourceFlags = 0;
		ImageUsage imageUsage;
		BufferUsage bufferUsage;
	};

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
