/*
 * =====================================================================================
 *
 *       Filename:  GHIImageUsage.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_IMAGE_USAGE_H
#define SOURCE_CORE_GHI_IMAGE_USAGE_H

#include "GHIDefine.h"

namespace GHI
{

class ImageUsage
{
public:
	inline bool ForSampler(void) const
	{
		return sampledImage == TRUE;
	}

	inline bool ForStorage(void) const
	{
		return storageImage == TRUE;
	}

	inline bool ForColor(void) const
	{
		return colorImage == TRUE;
	}

	inline bool ForDepthStencil(void) const
	{
		return depthStencil == TRUE;
	}

	inline bool ForTransient(void) const
	{
		return transientImage == TRUE;
	}

	inline bool ForInput(void) const
	{
		return inputImage == TRUE;
	}

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

}

#endif
