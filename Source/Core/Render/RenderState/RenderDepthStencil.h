/*
 * RenderDepthStencil.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSTATE_RENDERDEPTHSTENCIL_H_
#define SOURCE_CORE_RENDER_RENDERSTATE_RENDERDEPTHSTENCIL_H_

#include "RenderStateEnum.h"

namespace Render
{

class DepthStencil
{
public:
	DepthStencil(void) = default;
	~DepthStencil(void) = default;

public:
	bool depthTestEnable = true;
	bool depthWriteEnable = true;
	bool depthBoundsTestEnable = false;
	bool stencilTestEnable = false;
	float minDepthBounds = 0.0f;
	float maxDepthBounds = 0.0f;

public:
	CompareOperation depthCompareOp = CompareOperation::COMPARE_OP_LESS_OR_EQUAL;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSTATE_RENDERDEPTHSTENCIL_H_ */
