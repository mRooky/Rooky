/*
 * CoreTransform.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETRANSFORM_H_
#define SOURCE_CORE_CORETRANSFORM_H_

#include "RenderVector.h"

namespace Core
{

class Transform
{
public:
	Transform(void);
	~Transform(void);

public:
	inline void SetScale(const Render::Vector3f& scale) { mScale = scale; }
	inline void SetPosition(const Render::Vector3f& position) { mPosition = position; }
	inline void SetOrientation(const Render::Vector4f& orientation) { mOrientation = orientation; }

public:
	inline const Render::Vector3f& GetScale(void) const { return mScale; }
	inline const Render::Vector3f& GetPosition(void) const { return mPosition; }
	inline const Render::Vector4f& GetOrientation(void) const { return mOrientation; }

public:
	Render::Vector3f mScale = {};
	Render::Vector3f mPosition = {};
	Render::Vector4f mOrientation = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETRANSFORM_H_ */
