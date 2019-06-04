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
#include "MathSphere.h"
#include <array>

namespace Math
{
class AABB;

enum class PlaneType : uint32_t
{
	NEAR,
	FAR,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
};

static inline uint32_t PlaneTypeIndex(PlaneType type)
{
	return static_cast<uint32_t>(type);
}

class Frustum
{
public:
	Frustum(void);
	~Frustum(void);

public:
	bool Contain(const AABB& aabb) const;
	bool Contain(const Sphere& sphere) const;

public:
	inline const Plane& GetPlane(PlaneType type) const
	{
		uint32_t index = PlaneTypeIndex(type);
		return mPlanes.at(index);
	}

public:
	inline void SetFov(float fov, float near, float far)
	{
		mFov = fov;
		mFar = far;
		mNear = near;
	}

public:
	inline float GetFov(void) const { return mFov; }
	inline float GetNear(void) const { return mNear; }
	inline float GetFar(void) const { return mFar; }
	inline const Matrix& GetMatrix(void) const { return mMatrix; }

protected:
	float mFov = 45.0f;
	float mNear = 0.1f;
	float mFar = 100.0f;
	Matrix mMatrix = {};
	std::array<Plane, 6> mPlanes = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATH_MATHFRUSTUM_H_ */
