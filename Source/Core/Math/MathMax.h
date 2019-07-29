/*
 * =====================================================================================
 *
 *       Filename:  MathMax.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_MAX_H
#define SOURCE_CORE_MATH_MAX_H

namespace Math
{

template<typename T>
static inline T Max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

}

#endif
