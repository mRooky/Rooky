/*
 * MathSphere.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHSPHERE_H_
#define SOURCE_CORE_MATH_MATHSPHERE_H_

#include "MathVector.h"

namespace Math
{

class Sphere
{
public:
	Sphere(void);
	~Sphere(void);

public:
	Sphere(float radius, const Vector3f& center)
	{
		Set(radius, center);
	}

public:
	inline void Set(float radius, const Vector3f& center)
	{
		mRadius = radius;
		mCenter = center;
	}

public:
	inline void SetRadius(float radius)
	{
		mRadius = radius;
	}

	inline void SetCenter(const Vector3f& center)
	{
		mCenter = center;
	}

public:
	inline float GetRadius(void) const
	{
		return mRadius;
	}

	inline const Vector3f& GetCenter(void) const
	{
		return mCenter;
	}

private:
	float mRadius = 0.0f;
	Vector3f mCenter = {};
};

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHSPHERE_H_ */
