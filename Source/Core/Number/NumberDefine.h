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

#ifdef __linux__

#if __BYTE_ORDER__==__ORDER_LITTLE_ENDIAN__
#define PLATFORM_LITTLE_ENDIAN 1
#endif

#else

#if 0
#define PLATFORM_LITTLE_ENDIAN 1
#endif

#endif

namespace Number
{

typedef struct Float16Components
{
#ifdef PLATFORM_LITTLE_ENDIAN
	uint32_t mantissa :10;
	uint32_t exponent :5;
	uint32_t sign :1;
#else
	uint32_t sign :1;
	uint32_t exponent :5;
	uint32_t mantissa :10;
#endif
} Float16Components;

typedef struct Float32Components
{
#ifdef PLATFORM_LITTLE_ENDIAN
	uint32_t mantissa :23;
	uint32_t exponent :8;
	uint32_t sign :1;
#else
	uint32_t sign :1;
	uint32_t exponent :8;
	uint32_t mantissa :23;
#endif
} Float32Components;

typedef struct Float64Components
{
#ifdef PLATFORM_LITTLE_ENDIAN
	uint64_t mantissa :52;
	uint64_t exponent :11;
	uint64_t sign :1;
#else
	uint64_t sign :1;
	uint64_t exponent :11;
	uint64_t mantissa :52;
#endif
} Float64Components;

typedef float Real;

static inline bool CloseEnough(const float& v1, const float& v2)
{
	return std::abs(v1 - v2) < std::numeric_limits<float>::epsilon();
}

}

#endif /* SOURCE_CORE_RENDER_RENDERMATH_H_ */
