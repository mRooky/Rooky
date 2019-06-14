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

enum ResourceType : uint32_t
{
	IMAGE   = 0,
	BUFFER  = 1,
	SAMPLER = 2,
	UNKNOWN = ~0u
};

class UsageType
{
public:
	UsageType(void) {};
	~UsageType(void) {};

public:
	inline bool CPUAccessable(void) const { return (cpuAccess == TRUE); }

public:
	inline bool operator!=(const UsageType& other) const
	{
		return !(*this == other);
	}

	inline bool operator==(const UsageType& other) const
	{
		return (allUsageFlags == other.allUsageFlags);
	}

public:
	union
	{
		struct
		{
			uint16_t cpuAccess 		: 1;
			uint16_t read           : 1;
			uint16_t write          : 1;
			// Buffer Flags
			uint16_t indexBuffer	: 1;
			uint16_t vertexBuffer	: 1;
			uint16_t uniformBuffer	: 1;
			uint16_t storageBuffer	: 1;
			uint16_t indirectBuffer	: 1;
			uint16_t uniformTexel	: 1;
			uint16_t storageTexel	: 1;
			// Image Flags
			uint16_t sampledImage	: 1;
			uint16_t storageImage	: 1;
			uint16_t colorImage		: 1;
			uint16_t depthStencil	: 1;
			uint16_t transientImage	: 1;
			uint16_t inputImage		: 1;
			// Reserve Flags
			uint16_t Reserved		: 16;
		};
		uint32_t allUsageFlags = 0;
	};
	ResourceType type = ResourceType::UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERUSAGETYPE_H_ */
