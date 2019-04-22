/*
 * CoreFrustum.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREFRUSTUM_H_
#define SOURCE_CORE_COREFRUSTUM_H_

#include "MathFloat.hpp"
#include "MathMatrix.hpp"
#include "CorePlane.h"

namespace Core
{

class Frustum
{
public:
	Frustum(void);
	~Frustum(void);

public:
	Plane GetPlane(FrustumPlane type);

public:
	inline void SetFov(Math::Float fov) { mFov = fov; }
	inline void SetNear(Math::Float near) { mNear = near; }
	inline void SetFar(Math::Float far) { mFar = far; }

public:
	inline Math::Float GetFov(void) const { return mFov; }
	inline Math::Float GetNear(void) const { return mNear; }
	inline Math::Float GetFar(void) const { return mFar; }

public:
	inline const Math::Matrix& GetMatrax(void) const { return mMatrix; }
	inline void GetMatrax(const Math::Matrix& matrix) { mMatrix = matrix; }

protected:
	Math::Float mFov = 45.0f;
	Math::Float mNear = 0.1f;
	Math::Float mFar = 100.0f;
	Math::Matrix mMatrix = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREFRUSTUM_H_ */
