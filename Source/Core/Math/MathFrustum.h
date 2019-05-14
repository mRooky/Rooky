/*
 * CoreFrustum.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHFRUSTUM_H_
#define SOURCE_CORE_MATH_MATHFRUSTUM_H_

#include "MathMatrix.h"
#include "MathPlane.h"

namespace Math
{
class AABB;
class Frustum
{
public:
	Frustum(void);
	~Frustum(void);

public:
	Plane GetPlane(FrustumPlane type);

public:
	bool Contain(const AABB& aabb) const { return true; }

public:
	inline void SetFov(float fov) { mFov = fov; }
	inline void SetNear(float near) { mNear = near; }
	inline void SetFar(float far) { mFar = far; }

public:
	inline float GetFov(void) const { return mFov; }
	inline float GetNear(void) const { return mNear; }
	inline float GetFar(void) const { return mFar; }

public:
	inline const Matrix& GetMatrax(void) const { return mMatrix; }
	inline void GetMatrax(const Matrix& matrix) { mMatrix = matrix; }

protected:
	float mFov = 45.0f;
	float mNear = 0.1f;
	float mFar = 100.0f;
	Matrix mMatrix = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATH_MATHFRUSTUM_H_ */
