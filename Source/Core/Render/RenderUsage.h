/*
 * RenderUsageEnum.h
 *
 *  Created on: Feb 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERUSAGE_H_
#define SOURCE_CORE_RENDER_RENDERUSAGE_H_

#include "RenderEnum.h"

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
	AllocateType allocate;
	ResourceType type = ResourceType::RESOURCE_TYPE_UNKNOWN;
	union
	{
		ImageUsage imageUsage;
		BufferUsage bufferUsage;
	};

public:
	inline bool CPUAccessable(void) const
	{
		return allocate.CPUAccess == 1;
	}

public:
	static ResourceUsage GetImageUsage(bool access);
	static ResourceUsage GetBufferUsage(bool access);
};

}

#endif /* SOURCE_CORE_RENDER_RENDERUSAGE_H_ */
