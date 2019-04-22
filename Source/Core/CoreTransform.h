/*
 * CoreTransform.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETRANSFORM_H_
#define SOURCE_CORE_CORETRANSFORM_H_

#include "MathVector.h"

namespace Core
{

class Transform
{
public:
	Transform(void);
	~Transform(void);

public:
	inline void SetScale(const Math::Vector3f& scale) { mScale = scale; }
	inline void SetPosition(const Math::Vector3f& position) { mPosition = position; }
	inline void SetOrientation(const Math::Vector4f& orientation) { mOrientation = orientation; }

public:
	inline const Math::Vector3f& GetScale(void) const { return mScale; }
	inline const Math::Vector3f& GetPosition(void) const { return mPosition; }
	inline const Math::Vector4f& GetOrientation(void) const { return mOrientation; }

public:
	Math::Vector3f mScale = {};
	Math::Vector3f mPosition = {};
	Math::Vector4f mOrientation = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETRANSFORM_H_ */
