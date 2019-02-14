/*
 * RenderMath.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMATH_H_
#define SOURCE_CORE_RENDER_RENDERMATH_H_

#include "MathClasses.h"

namespace Render
{

typedef Math::Extent2<int32_t> Extent2;
typedef Math::Extent3<int32_t> Extent3;
typedef Math::Vector2<int32_t> Offset2;

typedef struct Viewport {
    float    x;
    float    y;
    float    width;
    float    height;
    float    minDepth;
    float    maxDepth;
} Viewport;

typedef struct Rect2D {
	Offset2    offset;
    Extent2    extent;
} Rect2D;

}

#endif /* SOURCE_CORE_RENDER_RENDERMATH_H_ */
