/*
 * CorePlane.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPLANE_H_
#define SOURCE_CORE_COREPLANE_H_

#include "MathFloat.hpp"
#include "MathVector.h"

namespace Core
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
	inline void SetDistance(Math::Float distance) { mDistance = distance; }
	inline void GetDirection(const Math::Vector3f& direction) { mDirection = direction; }

public:
	inline Math::Float GetDistance(void) const { return mDistance; }
	inline const Math::Vector3f& GetDirection(void) const { return mDirection; }

public:
	Math::Float mDistance = 0.0f;
	Math::Vector3f mDirection = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPLANE_H_ */
