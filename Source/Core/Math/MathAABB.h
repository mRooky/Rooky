/*
 * RenderAABB.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERMATH_RENDERAABB_H_
#define SOURCE_CORE_GHI_RENDERMATH_RENDERAABB_H_

#include "MathVector.h"

namespace Math
{

template<typename T>
class AABB_t
{
public:
	AABB_t(void) = default;
	~AABB_t(void) = default;

public:
	AABB_t(const Vector3_t<T>& min, const Vector3_t<T>& max)
	{
		Set(min, max);
	}

public:
	inline void Set(const Vector3_t<T>& min, const Vector3_t<T>& max)
	{
		this->min = min;
		this->max = max;
	}

public:
	inline Vector3_t<T> GetCenter(void) const { return (min + max) * 0.5f; }
	inline float GetRadius(void) const { return (min - max).Length() * 0.5f; }

public:
	inline void SetMin(const Vector3_t<T>& min) { this->min = min; }
	inline void SetMax(const Vector3_t<T>& max) { this->max = max; }

public:
	inline const Vector3_t<T>& GetMin(void) const { return min; }
	inline const Vector3_t<T>& GetMax(void) const { return max; }

public:
	Vector3_t<T> min = {};
	Vector3_t<T> max = {};
};

typedef AABB_t<float> AABB;

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERAABB_H_ */
