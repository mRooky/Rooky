/*
 * CoreFrustum.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREFRUSTUM_H_
#define SOURCE_CORE_COREFRUSTUM_H_

#include "CorePlane.h"
#include "RenderFloat.hpp"
#include "RenderVector.hpp"
#include "RenderMatrix.hpp"

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
	inline void SetFov(Render::Float fov) { mFov = fov; }
	inline void SetNear(Render::Float near) { mNear = near; }
	inline void SetFar(Render::Float far) { mFar = far; }

public:
	inline Render::Float GetFov(void) const { return mFov; }
	inline Render::Float GetNear(void) const { return mNear; }
	inline Render::Float GetFar(void) const { return mFar; }

public:
	inline const Render::Matrix& GetMatrax(void) const { return mMatrix; }
	inline void GetMatrax(const Render::Matrix& matrix) { mMatrix = matrix; }

protected:
	Render::Float mFov = 45.0f;
	Render::Float mNear = 0.1f;
	Render::Float mFar = 100.0f;
	Render::Matrix mMatrix = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREFRUSTUM_H_ */
