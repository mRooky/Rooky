/*
 * RenderTypes.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERTYPES_H_
#define SOURCE_CORE_RENDER_RENDERTYPES_H_

#include <cstdint>

namespace Render
{
	enum class ImageType : uint32_t
	{
		IMAGE_TYPE_1D,
		IMAGE_TYPE_2D,
		IMAGE_TYPE_3D,
		IMAGE_TYPE_CUBE,
		IMAGE_TYPE_1D_ARRAY,
		IMAGE_TYPE_2D_ARRAY,
		IMAGE_TYPE_CUBE_ARRAY,
		IMAGE_TYPE_UNKNOWN = ~0u
	};
}

#endif /* SOURCE_CORE_RENDER_RENDERTYPES_H_ */
