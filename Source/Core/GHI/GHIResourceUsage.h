/*
 * RenderUsageType.h
 *
 *  Created on: Apr 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERUSAGETYPE_H_
#define SOURCE_CORE_GHI_RENDERUSAGETYPE_H_

#include "GHIMemoryUsage.h"
#include "GHIImageUsage.h"
#include "GHIBufferUsage.h"

namespace GHI
{

class ResourceUsage
{
public:
	ResourceUsage(void) {};
	~ResourceUsage(void) {};

public:
	inline bool operator!=(const ResourceUsage& other) const
	{
		return !(*this == other);
	}

	inline bool operator==(const ResourceUsage& other) const
	{
		return (allFlags == other.allFlags) && (memoryUsage == other.memoryUsage);
	}

public:
	inline ImageUsage& GetImageUsage(void)
	{
		return imageUsage;
	}

	inline BufferUsage& GetBufferUsage(void)
	{
		return bufferUsage;
	}

	inline MemoryUsage& GetMemoryUsage(void)
	{
		return memoryUsage;
	}

public:
	union
	{
		uint8_t allFlags = 0;
		ImageUsage imageUsage;
		BufferUsage bufferUsage;
	};
	MemoryUsage memoryUsage = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERUSAGETYPE_H_ */
