/*
 * =====================================================================================
 *
 *       Filename:  GHIImageType.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_INDEX_TYPE_H
#define SOURCE_CORE_GHI_INDEX_TYPE_H

#include <cstdint>

namespace GHI
{
	enum class ImageType : uint32_t
	{
		IT_1D,
		IT_2D,
		IT_3D,
		IT_CUBE,
		IT_1D_ARRAY,
		IT_2D_ARRAY,
		IT_CUBE_ARRAY,
		IT_UNKNOWN = ~0u
	};


}

#endif
