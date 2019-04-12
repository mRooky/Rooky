/*
 * RenderUsageType.h
 *
 *  Created on: Apr 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERUSAGETYPE_H_
#define SOURCE_CORE_RENDER_RENDERUSAGETYPE_H_

#include "RenderDefine.h"

namespace Render
{

enum ResourceType : uint8_t
{
	RESOURCE_TYPE_IMAGE,
	RESOURCE_TYPE_BUFFER,
	RESOURCE_TYPE_SAMPLER,
	RESOURCE_TYPE_UNKNOWN
};

class UsageType
{
public:
	UsageType(void) = default;
	~UsageType(void) = default;

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
			uint16_t source 		: 1;
			uint16_t destination 	: 1;
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
	ResourceType type = ResourceType::RESOURCE_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERUSAGETYPE_H_ */
