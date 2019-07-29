/*
 * =====================================================================================
 *
 *       Filename:  MathMax.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_MIN_H
#define SOURCE_CORE_MATH_MIN_H

namespace Math
{

template<typename T>
static inline T Min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

}

#endif
