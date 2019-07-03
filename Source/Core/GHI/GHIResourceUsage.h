/*
 * RenderUsageType.h
 *
 *  Created on: Apr 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERUSAGETYPE_H_
#define SOURCE_CORE_GHI_RENDERUSAGETYPE_H_

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


class ImageUsage
{
public:
	ImageUsage(void) {}
	~ImageUsage(void) {}

public:
	union
	{
		struct
		{
			uint8_t sampledImage	: 1;
			uint8_t storageImage	: 1;
			uint8_t colorImage		: 1;
			uint8_t depthStencil	: 1;
			uint8_t transientImage	: 1;
			uint8_t inputImage		: 1;
			uint8_t reserved        : 2;
		};
		uint8_t allFlags = 0;
	};
};


class BufferUsage
{
public:
	BufferUsage(void) {}
	~BufferUsage(void) {}

public:
	union
	{
		struct
		{
			uint8_t indexBuffer	    : 1;
			uint8_t vertexBuffer	: 1;
			uint8_t uniformBuffer	: 1;
			uint8_t storageBuffer	: 1;
			uint8_t indirectBuffer	: 1;
			uint8_t uniformTexel	: 1;
			uint8_t storageTexel	: 1;
			uint8_t reserved        : 1;
		};
		uint8_t allFlags = 0;
	};
};

enum ResourceType : uint32_t
{
	IMAGE   = 0,
	BUFFER  = 1,
	SAMPLER = 2,
	UNKNOWN = ~0u
};

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
	inline ImageUsage& GetImageUsage(void) { return imageUsage; }
	inline BufferUsage& GetBufferUsage(void) { return bufferUsage; }
	inline MemoryUsage& GetMemoryUsage(void) { return memoryUsage; }

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
