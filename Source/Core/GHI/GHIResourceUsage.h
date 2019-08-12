/*
 * =====================================================================================
 *
 *       Filename:  GHIResourceUsage.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_RESOURCE_USAGE_H
#define SOURCE_CORE_GHI_RESOURCE_USAGE_H

#include "GHIImageUsage.h"
#include "GHIBufferUsage.h"
#include "GHIMemoryType.h"

namespace GHI
{

class ResourceUsage
{
public:
	ResourceUsage(void) {}
	~ResourceUsage(void) {}

public:
	inline const ImageUsage& GetImageUsage(void) const
	{
		return imageUsage;
	}

	inline const BufferUsage& GetBufferUsage(void) const
	{
		return bufferUsage;
	}

	inline const MemoryType& GetMemoryType(void) const
	{
		return memoryType;
	}

public:
	inline ResourceUsage& operator=(const ImageUsage& usage)
	{
		imageUsage = usage;
		return *this;
	}

	inline ResourceUsage& operator=(const BufferUsage& usage)
	{
		bufferUsage = usage;
		return *this;
	}

public:
	inline bool operator==(const ResourceUsage& other) const
	{
		return memoryType == other.memoryType
			&& resourceFlags == other.resourceFlags;
	}

public:
	union
	{
		uint8_t resourceFlags = 0;
		ImageUsage imageUsage;
		BufferUsage bufferUsage;
	};
	MemoryType memoryType = {};

};

}

#endif
