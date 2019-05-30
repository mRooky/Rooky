/*
 * MathExtent3.h
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHEXTENT3_H_
#define SOURCE_CORE_MATH_MATHEXTENT3_H_

#include "MathExtent2.h"

namespace Math
{

template<typename T>
class Extent3_t
{
public:
	inline T GetVolume(void) const
	{
		return width * height * depth;
	}

public:
	template<typename O>
	inline Extent3_t& operator=(const Extent2_t<O>& extent)
	{
		this->width = static_cast<T>(extent.width);
		this->height = static_cast<T>(extent.height);
		this->depth = 1;
		return *this;
	}

public:
	inline void Set(T width, T height, T depth)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
	}

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
	T depth = static_cast<T>(0);
};

typedef Extent3_t<int32_t> Extent3Di;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHEXTENT3_H_ */
