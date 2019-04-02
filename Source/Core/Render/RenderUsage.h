/*
 * RenderUsageEnum.h
 *
 *  Created on: Feb 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERUSAGE_H_
#define SOURCE_CORE_RENDER_RENDERUSAGE_H_

#include "RenderEnum.h"
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

class AllocateType
{
public:
	AllocateType(void) = default;
	~AllocateType(void) = default;

public:
	inline bool operator==(const AllocateType& other) const
	{
		return (TypeFlags == other.TypeFlags);
	}

public:
	union
	{
		struct
		{
			uint8_t Source 		:1;
			uint8_t Destination :1;
			uint8_t CPUAccess 	:1;
			uint8_t Reserved 	:5;
		};
		uint8_t TypeFlags = 0;
	};
};

class ImageUsage
{
public:
	ImageUsage(void) = default;
	~ImageUsage(void) = default;

public:
	inline bool operator==(const ImageUsage& other) const
	{
		return (UsageFlags == other.UsageFlags);
	}

public:
	union
	{
		struct
		{
			uint8_t SampledImage		: 1;
			uint8_t StorageImage		: 1;
			uint8_t ColorImage			: 1;
			uint8_t DepthStencil		: 1;
			uint8_t TransientImage		: 1;
			uint8_t InputImage			: 1;
			uint8_t Reserved			: 2;
		};
		uint8_t UsageFlags = 0;
	};
};

class BufferUsage
{
public:
	BufferUsage(void) = default;
	~BufferUsage(void) = default;

public:
	inline bool operator==(const BufferUsage& other) const
	{
		return (UsageFlags == other.UsageFlags);
	}

public:
	union
	{
		struct
		{
			uint8_t IndexBuffer			: 1;
			uint8_t VertexBuffer		: 1;
			uint8_t UniformBuffer		: 1;
			uint8_t StorageBuffer		: 1;
			uint8_t IndirectBuffer		: 1;
			uint8_t UniformTexel		: 1;
			uint8_t StorageTexel		: 1;
			uint8_t Reserved			: 1;
		};
		uint8_t UsageFlags = 0;
	};
};

class ResourceUsage
{
public:
	ResourceUsage(void) = default;
	~ResourceUsage(void) = default;

public:
	inline bool CPUAccessable(void) const
	{
		return (allocate.CPUAccess == TRUE);
	}

public:
	inline bool operator==(const ResourceUsage& other) const
	{
		return (type == other.type)
				&& (allocate == other.allocate)
				&& (allUsageFlags == other.allUsageFlags);
	}

	inline bool operator!=(const ResourceUsage& other) const
	{
		return !(*this == other);
	}

public:
	static ResourceUsage GetImageUsage(bool access);
	static ResourceUsage GetBufferUsage(bool access);

public:
	union
	{
		union
		{
			ImageUsage imageUsage;
			BufferUsage bufferUsage;
		};
		uint8_t allUsageFlags = 0;
	};
	AllocateType allocate;
	ResourceType type = ResourceType::RESOURCE_TYPE_UNKNOWN;
};

}

#endif /* SOURCE_CORE_RENDER_RENDERUSAGE_H_ */
