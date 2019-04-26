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
	inline Vector3f GetCenter(void) const { return (min + max) * 0.5f; }
	inline float GetRadius(void) const { return (min - max).Length() * 0.5f; }

public:
	Vector3f min = {};
	Vector3f max = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERAABB_H_ */
