/*
 * =====================================================================================
 *
 *       Filename:  MathClamp.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_CLAMP_H
#define SOURCE_CORE_MATH_CLAMP_H

#include "MathMax.h"
#include "MathMin.h"
#include <cassert>

namespace Math
{

template<typename T>
static inline T Clamp(const T& value, const T& lower, const T& upper)
{
	assert(lower < upper);
	return Min(upper, Max(value, lower));
}

}

#endif
