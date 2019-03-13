/*
 * RenderRasterization.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_STATE_RENDERRASTERIZATION_H_
#define SOURCE_CORE_RENDER_STATE_RENDERRASTERIZATION_H_

#include "RenderState.h"

namespace Render
{

class Rasterization
{
public:
	Rasterization(void) = default;
	~Rasterization(void) = default;

public:
	bool depthClampEnable = false;
	bool rasterizerDiscardEnable = false;
	bool depthBiasEnable = false;
	float depthBiasConstantFactor = 0.0f;
	float depthBiasClamp = 0.0f;
	float depthBiasSlopeFactor = 0.0f;
	float lineWidth = 1.0f;

public:
	FrontFace frontFace = FrontFace::FRONT_FACE_CCW;
	PolygonMode polygonMode = PolygonMode::POLYGON_MODE_FILL;
	CullFaceSide cullMode = CullFaceSide::CULL_FACE_SIDE_NONE;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_STATE_RENDERRASTERIZATION_H_ */