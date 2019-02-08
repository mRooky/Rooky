/*
 * MathExtent3.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHEXTENT3_HPP_
#define SOURCE_CORE_MATH_MATHEXTENT3_HPP_

#include <cstdint>

namespace Math
{

template<typename T>
class Extent3
{
public:
	Extent3(void) = default;
	Extent3(T w, T h, T d) : width(w), height(h), depth(d) {}
	~Extent3(void) = default;

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
	T depth = static_cast<T>(0);
};

}

#endif /* SOURCE_CORE_MATH_MATHEXTENT3_HPP_ */
