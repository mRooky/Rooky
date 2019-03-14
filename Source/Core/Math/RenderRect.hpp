/*
 * RenderRect.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_RENDERRECT_HPP_
#define SOURCE_CORE_MATH_RENDERRECT_HPP_

#include <RenderExtent.hpp>
#include <RenderVector.hpp>

namespace Render
{

typedef Vector2_t<float> Offset2;

class Rect2D
{
public:
	Offset2 offset = {};
    Extent2 extent = {};
};

}

#endif /* SOURCE_CORE_MATH_RENDERRECT_HPP_ */
