/*
 * RenderColorBlend.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_STATE_RENDERCOLORBLEND_H_
#define SOURCE_CORE_RENDER_STATE_RENDERCOLORBLEND_H_

#include "RenderState.h"

namespace Render
{

class ColorBlend
{
public:
	ColorBlend(void) = default;
	~ColorBlend(void) = default;

public:
	bool blendEnable = false;
	BlendFactor srcColorBlendFactor = BlendFactor::BLEND_FACTOR_SRC_COLOR;
	BlendFactor dstColorBlendFactor = BlendFactor::BLEND_FACTOR_DST_COLOR;
	BlendOperation colorBlendOp = BlendOperation::BLEND_OPERATION_ADD;
	BlendFactor srcAlphaBlendFactor = BlendFactor::BLEND_FACTOR_SRC_ALPHA;
	BlendFactor dstAlphaBlendFactor = BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	BlendOperation alphaBlendOp = BlendOperation::BLEND_OPERATION_ADD;
	uint32_t colorWriteMask = 0xF;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_STATE_RENDERCOLORBLEND_H_ */