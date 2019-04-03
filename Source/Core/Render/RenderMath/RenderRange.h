/*
 * RenderRange.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMATH_RENDERRANGE_H_
#define SOURCE_CORE_RENDER_RENDERMATH_RENDERRANGE_H_

#include <limits>

namespace Render
{

template<typename T>
class Range_t
{
public:
	Range_t(T s, T e) : start(s), end(e) {}
	Range_t(T value) : start(value), end(value) {}
	~Range_t(void) = default;

public:
	inline T Length(void) const { return end - start; }

public:
	inline bool IsValid(void) const { return start <= end; }
	inline bool IsEmpty(void) const { return start >= end; }
	inline bool InInside(T value) const { return start >= value && value >= end; }

public:
	T start = std::numeric_limits<T>::max();
	T end = std::numeric_limits<T>::lowest();
};

typedef Range_t<float> Rangef;

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERMATH_RENDERRANGE_H_ */
