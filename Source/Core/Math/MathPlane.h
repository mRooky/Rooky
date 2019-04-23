/*
 * CorePlane.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHPLANE_H_
#define SOURCE_CORE_MATH_MATHPLANE_H_

#include "MathFloat.hpp"
#include "MathVector.h"

namespace Math
{

enum class FrustumPlane : uint32_t
{
	FRUSTUM_PLANE_FRONT,
	FRUSTUM_PLANE_BACK,
	FRUSTUM_PLANE_LEFT,
	FRUSTUM_PLANE_RIGHT,
	FRUSTUM_PLANE_TOP,
	FRUSTUM_PLANE_BOTTOM,
	FRUSTUM_PLANE_COUNT,
	FRUSTUM_PLANE_UNKONWN = ~0U
};

class Plane
{
public:
	Plane(void);
	~Plane(void);

public:
	inline void SetDistance(Float distance) { mDistance = distance; }
	inline void GetDirection(const Vector3f& direction) { mDirection = direction; }

public:
	inline Float GetDistance(void) const { return mDistance; }
	inline const Vector3f& GetDirection(void) const { return mDirection; }

public:
	Float mDistance = 0.0f;
	Vector3f mDirection = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATH_MATHPLANE_H_ */
