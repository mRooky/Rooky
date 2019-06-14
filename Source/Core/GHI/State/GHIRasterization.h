/*
 * RenderRasterization.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERRASTERIZATION_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERRASTERIZATION_H_

#include "GHIStateEnum.h"

namespace GHI
{

class Rasterization
{
public:
	Rasterization(void) = default;
	~Rasterization(void) = default;

public:
	bool operator==(const Rasterization& other) const;

public:
	bool depthClampEnable = false;
	bool rasterizerDiscardEnable = false;
	bool depthBiasEnable = false;
	float depthBiasConstantFactor = 0.0f;
	float depthBiasClamp = 0.0f;
	float depthBiasSlopeFactor = 0.0f;
	float lineWidth = 1.0f;

public:
	FrontFace frontFace = FrontFace::CCW;
	PolygonMode polygonMode = PolygonMode::FILL;
	CullFaceSide cullMode = CullFaceSide::NONE;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERRASTERIZATION_H_ */
