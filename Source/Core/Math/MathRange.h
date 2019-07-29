/*
 * RenderRange.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERMATH_RENDERRANGE_H_
#define SOURCE_CORE_GHI_RENDERMATH_RENDERRANGE_H_

#include <limits>

namespace Math
{

template<typename T>
class Range_t
{
public:
	Range_t(void) = default;
	Range_t(const T& offset, const T& size)
	{
		Set(offset, size);
	}

public:
	~Range_t(void) = default;

public:
	inline void Set(const T& offset, const T& size)
	{
		this->offset = offset;
		this->size = size;
	}

public:
	inline T GetOffset(void) const { return offset; }
	inline T GetSize(void) const { return size; }
	inline bool IsValid(void) const { return size > 0; }

public:
	T offset = static_cast<T>(0);
	T size = static_cast<T>(0);

};

typedef Range_t<float> Rangef;

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERRANGE_H_ */
