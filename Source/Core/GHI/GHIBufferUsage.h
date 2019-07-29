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
