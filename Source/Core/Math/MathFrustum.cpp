/*
 * CoreFrustum.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "MathFrustum.h"
#include <cassert>

namespace Math
{

Frustum::Frustum(void)
{
}

Frustum::~Frustum(void)
{
}

bool Frustum::Contain(const AABB& aabb) const
{
	return true;
}

bool Frustum::Contain(const Sphere& sphere) const
{
	return true;
}

} /* namespace Core */
