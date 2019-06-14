/*
 * RenderDepthStencil.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERDEPTHSTENCIL_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERDEPTHSTENCIL_H_

#include "GHIStateEnum.h"

namespace GHI
{

class DepthStencil
{
public:
	DepthStencil(void) = default;
	~DepthStencil(void) = default;

public:
	bool operator==(const DepthStencil& other) const;
	inline bool operator!=(const DepthStencil& other) const
	{
		return !(*this == other);
	}

public:
	inline DepthStencil& operator=(const DepthStencil& other)
	{
		depthTestEnable = other.depthTestEnable;
		depthWriteEnable = other.depthWriteEnable;
		depthBoundsTestEnable = other.depthBoundsTestEnable;
		stencilTestEnable = other.stencilTestEnable;
		minDepthBounds = other.minDepthBounds;
		maxDepthBounds = other.maxDepthBounds;
		return *this;
	}

public:
	bool depthTestEnable = true;
	bool depthWriteEnable = true;
	bool depthBoundsTestEnable = false;
	bool stencilTestEnable = false;
	float minDepthBounds = 0.0f;
	float maxDepthBounds = 0.0f;

public:
	CompareOperation depthCompareOp = CompareOperation::LESS_OR_EQUAL;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERDEPTHSTENCIL_H_ */
