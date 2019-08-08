/*
 * =====================================================================================
 *
 *       Filename:  GHIBufferUsage.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_BUFFER_USAGE_H
#define SOURCE_CORE_GHI_BUFFER_USAGE_H

#include "GHIDefine.h"

namespace GHI
{

class BufferUsage
{
public:
	BufferUsage(void) {}
	~BufferUsage(void) {}

public:
	inline bool ForIndex(void) const
	{
		return indexBuffer == TRUE;
	}

	inline bool ForVertex(void) const
	{
		return vertexBuffer == TRUE;
	}

	inline bool ForUniform(void) const
	{
		return uniformBuffer == TRUE;
	}

	inline bool ForStorage(void) const
	{
		return storageBuffer == TRUE;
	}

	inline bool ForIndirect(void) const
	{
		return indirectBuffer == TRUE;
	}

	inline bool ForUniformTexel(void) const
	{
		return uniformTexel == TRUE;
	}

	inline bool ForStorageTexel(void) const
	{
		return storageTexel == TRUE;
	}

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

}

#endif
