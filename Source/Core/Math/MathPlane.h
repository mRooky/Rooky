/*
 * CorePlane.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHPLANE_H_
#define SOURCE_CORE_MATH_MATHPLANE_H_

#include "MathVector.h"
#include <cstdint>

namespace Math
{

class Plane
{
public:
	Plane(void);
	~Plane(void);

public:
	inline void SetDistance(float distance) { mDistance = distance; }
	inline void GetDirection(const Vector3f& direction) { mDirection = direction; }

public:
	inline float GetDistance(void) const { return mDistance; }
	inline const Vector3f& GetDirection(void) const { return mDirection; }

public:
	float mDistance = 0.0f;
	Vector3f mDirection = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATH_MATHPLANE_H_ */
