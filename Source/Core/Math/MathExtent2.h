/*
 * MathExtent2.h
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHEXTENT2_H_
#define SOURCE_CORE_MATH_MATHEXTENT2_H_

#include <cstdint>

namespace Math
{

template<typename T>
class Extent2_t
{
public:
	Extent2_t(void) = default;
	template<typename O>
	Extent2_t(O width, O height)
	{
		Set(width, height);
	}

public:
	inline T GetArea(void) const
	{
		return width * height;
	}

public:
	template<typename O>
	inline void Set(O width, O height)
	{
		this->width = static_cast<T>(width);
		this->height = static_cast<T>(height);
	}

public:
	inline bool IsValid(void) const
	{
		return width * height > 0;
	}

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
};

typedef Extent2_t<int32_t> Extent2Di;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHEXTENT2_H_ */
