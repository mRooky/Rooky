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
	union ResourceHeap
	{
		struct
		{
			uint32_t Image		: 1;
			uint32_t Buffer		: 1;
			uint32_t Transform	: 1;
			uint32_t CPUAccess	: 1;
			uint32_t Reserved	: 28;
		};
		uint32_t Flags = 0;
	};

	union ResourceBinding
	{
		struct
		{
			uint32_t SampledImage		: 1;
			uint32_t StorageImage		: 1;
			uint32_t ColorImage			: 1;
			uint32_t DepthStencil		: 1;
			uint32_t TransientImage		: 1;
			uint32_t InputImage			: 1;
			uint32_t IndexBuffer		: 1;
			uint32_t VertexBuffer		: 1;
			uint32_t UniformBuffer		: 1;
			uint32_t StorageBuffer		: 1;
			uint32_t IndirectBuffer		: 1;
			uint32_t UniformTexel		: 1;
			uint32_t StorageTexel		: 1;
			uint32_t Reserved			: 19;
		};
		uint32_t Flags = 0;
	};

class ResourceUsage
{
public:
	ResourceUsage(void) = default;
	~ResourceUsage(void) = default;

public:
	ResourceHeap heap;
	ResourceBinding binding;

public:
	static ResourceUsage GetImageUsage(bool access);
	static ResourceUsage GetBufferUsage(bool access);
};

}

#endif /* SOURCE_CORE_RENDER_RENDERUSAGE_H_ */
