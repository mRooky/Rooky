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
	union BufferUsage
	{
		struct
		{
			uint32_t BufferUsageCommon			: 1;
			uint32_t BufferUsageIndex			: 1;
			uint32_t BufferUsageVertex			: 1;
			uint32_t BufferUsageUniform			: 1;
			uint32_t BufferUsageStorage			: 1;
			uint32_t BufferUsageIndirect		: 1;
			uint32_t BufferUsageUniformTexel	: 1;
			uint32_t BufferUsageStorageTexel	: 1;
			uint32_t BufferUsageReserved		: 24;
		};
		uint32_t BufferUsageFlags;
	};

	union ImageUsage
	{
		struct
		{
			uint32_t ImageUsageCommon					: 1;
			uint32_t ImageUsageSampled					: 1;
			uint32_t ImageUsageStorage					: 1;
			uint32_t ImageUsageColorAttachment			: 1;
			uint32_t ImageUsageDepthStencilAttachment	: 1;
			uint32_t ImageUsageTransientAttachment		: 1;
			uint32_t ImageUsageInputAttachment			: 1;
			uint32_t ImageUsageReserved					: 25;
		};
		uint32_t ImageUsageFlags;
	};
}

#endif /* SOURCE_CORE_RENDER_RENDERUSAGE_H_ */
