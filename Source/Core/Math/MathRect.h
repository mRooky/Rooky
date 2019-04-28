/*
 * RenderRect.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_RENDERRECT_HPP_
#define SOURCE_CORE_MATH_RENDERRECT_HPP_

#include "MathVector.h"
#include "MathExtent2.h"

namespace Math
{

template<typename F, typename I>
class Rect2D_t
{
public:
	Rect2D_t(void) = default;
	~Rect2D_t(void) = default;

public:
	template<typename O>
	Rect2D_t(const Extent2_t<O>& extent)
	{
		SetExtent(extent);
	}

	template<typename O>
	Rect2D_t(O width, O height)
	{
		SetExtent(width, height);
	}

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

	template<typename O>
	inline void SetExtent(const Extent2_t<O>& extent)
	{
		this->extent.width = static_cast<I>(extent.width);
		this->extent.height = static_cast<I>(extent.height);
	}

public:
	inline bool IsValid(void) const { return extent.GetArea() > 0; }

public:
	Vector2_t<F> offset = {};
	Extent2_t<I> extent = {};
};

typedef Rect2D_t<int32_t, int32_t> Rect2Di;

}

#endif /* SOURCE_CORE_MATH_RENDERRECT_HPP_ */
