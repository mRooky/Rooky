/*
 * RenderMath.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMATH_H_
#define SOURCE_CORE_RENDER_RENDERMATH_H_

#include <limits>
#include <cmath>
#include <cstdint>

#if 0
#define NUMBER_BIG_ENDIAN 1	// not support BIG-ENDIAN platform right now
#else
#define NUMBER_LITTLE_ENDIAN 1	// only LITTLE-ENDIAN platform right now
#endif

namespace Number
{

typedef float Real;

template<typename T>
static inline bool CloseEnough(const T& v1, const T& v2)
{
	return std::abs(v1 - v2) < std::numeric_limits<T>::epsilon();
}

}

#endif /* SOURCE_CORE_RENDER_RENDERMATH_H_ */
