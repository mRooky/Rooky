/*
 * GHIDepthStencil.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "GHIDepthStencil.h"
#include "MathFloat.h"

namespace GHI
{

bool DepthStencil::operator==(const DepthStencil& other) const
{
	bool equal = depthTestEnable == other.depthTestEnable
			&& depthWriteEnable == other.depthWriteEnable
			&& depthBoundsTestEnable == other.depthBoundsTestEnable
			&& stencilTestEnable == other.stencilTestEnable;

	if (true == equal)
	{
		return Math::CloseEnough(minDepthBounds, other.minDepthBounds)
				&& Math::CloseEnough(maxDepthBounds, other.maxDepthBounds);
	}
	return false;
}

}

