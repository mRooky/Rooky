/*
 * RenderMath.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMATH_H_
#define SOURCE_CORE_RENDER_RENDERMATH_H_

#include <cstdint>

namespace Render
{

typedef struct Extent2
{
	int32_t width;
	int32_t height;
}Extent2;

typedef struct Extent3
{
	int32_t width;
	int32_t height;
	int32_t depth;
}Extent3;

typedef struct Offset2
{
	float x;
	float y;
}Offset2;

typedef struct Viewport
{
    float    x;
    float    y;
    float    width;
    float    height;
    float    minDepth;
    float    maxDepth;
} Viewport;

typedef struct Rect2D
{
	Offset2    offset;
    Extent2    extent;
} Rect2D;

}

#endif /* SOURCE_CORE_RENDER_RENDERMATH_H_ */
