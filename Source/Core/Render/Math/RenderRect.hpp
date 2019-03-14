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

template<typename F, typename I>
class Rect2D_t
{
public:
	Rect2D_t(void) = default;
	~Rect2D_t(void) = default;

public:
	template<typename O>
	inline void SetOffset(O x, O y)
	{
		offset.x = static_cast<F>(x);
		offset.y = static_cast<F>(y);
	}

	template<typename O>
	inline void SetExtent(O width, O height)
	{
		extent.width = static_cast<I>(width);
		extent.height = static_cast<I>(height);
	}

public:
	Vector2_t<F> offset = {};
    Extent2_t<I> extent = {};
};

typedef Rect2D_t<float, int32_t> Rect2D;

}

#endif /* SOURCE_CORE_MATH_RENDERRECT_HPP_ */
