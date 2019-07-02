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

class AABB
{
public:
	AABB(void) = default;
	~AABB(void) = default;

public:
	AABB(const Vector3f& min, const Vector3f& max) { Set(min, max); }

public:
	inline void Set(const Vector3f& min, const Vector3f& max)
	{
		this->min = min;
		this->max = max;
	}

public:
	inline Vector3f GetCenter(void) const { return (min + max) * 0.5f; }
	inline float GetRadius(void) const { return (min - max).Length() * 0.5f; }

public:
	inline void SetMin(const Vector3f& min) { this->min = min; }
	inline void SetMax(const Vector3f& max) { this->max = max; }

public:
	inline const Vector3f& GetMin(void) const { return min; }
	inline const Vector3f& GetMax(void) const { return max; }

public:
	Vector3f min = {};
	Vector3f max = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERAABB_H_ */
