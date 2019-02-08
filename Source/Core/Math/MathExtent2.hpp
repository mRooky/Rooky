/*
 * MathExtent2.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHEXTENT2_HPP_
#define SOURCE_CORE_MATH_MATHEXTENT2_HPP_

#include <cstdint>

namespace Math
{

template<typename T>
class Extent2
{
public:
	Extent2(void) = default;
	Extent2(T w, T h) : width(w), height(h){}
	~Extent2(void) = default;

public:
	inline int32_t GetArea(void) const { return width * height; }

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
};

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHEXTENT2_HPP_ */
