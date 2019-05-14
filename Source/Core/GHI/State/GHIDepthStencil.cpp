/*
 * GHIDepthStencil.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "NumberFloat.h"
#include "GHIDepthStencil.h"

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
		return Number::CloseEnough(minDepthBounds, other.minDepthBounds)
				&& Number::CloseEnough(maxDepthBounds, other.maxDepthBounds);
	}
	return false;
}

}

