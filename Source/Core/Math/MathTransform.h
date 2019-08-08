/*
 * CoreTransform.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHTRANSFORM_H_
#define SOURCE_CORE_MATH_MATHTRANSFORM_H_

#include "MathVector.h"

namespace Math
{

class Transform
{
public:
	Transform(void);
	~Transform(void);

public:
	inline void SetScale(const Vector3f& scale)
	{
		mScale = scale;
	}

	inline void SetPosition(const Vector3f& position)
	{
		mPosition = position;
	}

	inline void SetOrientation(const Vector4f& orientation)
	{
		mOrientation = orientation;
	}

public:
	inline const Vector3f& GetScale(void) const
	{
		return mScale;
	}

	inline const Vector3f& GetPosition(void) const
	{
		return mPosition;
	}

	inline const Vector4f& GetOrientation(void) const
	{
		return mOrientation;
	}

public:
	Vector3f mScale = {};
	Vector3f mPosition = {};
	Vector4f mOrientation = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATH_MATHTRANSFORM_H_ */
