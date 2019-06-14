/*
 * RenderColorBlend.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERCOLORBLEND_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERCOLORBLEND_H_

#include "GHIStateEnum.h"

namespace GHI
{

class ColorBlend
{
public:
	ColorBlend(void) = default;
	~ColorBlend(void) = default;

public:
	inline bool operator==(const ColorBlend& other) const
	{
		return blendEnable == other.blendEnable
			&& srcColorBlendFactor == other.srcColorBlendFactor
			&& dstColorBlendFactor == other.dstColorBlendFactor
			&& colorBlendOp == other.colorBlendOp
			&& srcAlphaBlendFactor == other.srcAlphaBlendFactor
			&& dstAlphaBlendFactor == other.dstAlphaBlendFactor
			&& alphaBlendOp == other.alphaBlendOp
			&& colorWriteMask == other.colorWriteMask;
	}

	inline bool operator!=(const ColorBlend& other) const
	{
		return !(*this == other);
	}

public:
	inline ColorBlend& operator=(const ColorBlend& other)
	{
		blendEnable = other.blendEnable;
		srcColorBlendFactor = other.srcColorBlendFactor;
		dstColorBlendFactor = other.dstColorBlendFactor;
		colorBlendOp = other.colorBlendOp;
		srcAlphaBlendFactor = other.srcAlphaBlendFactor;
		dstAlphaBlendFactor = other.dstAlphaBlendFactor;
		alphaBlendOp = other.alphaBlendOp;
		colorWriteMask = other.colorWriteMask;
		return *this;
	}

public:
	bool blendEnable = false;
	BlendFactor srcColorBlendFactor = BlendFactor::SRC_COLOR;
	BlendFactor dstColorBlendFactor = BlendFactor::DST_COLOR;
	BlendOperation colorBlendOp = BlendOperation::ADD;
	BlendFactor srcAlphaBlendFactor = BlendFactor::SRC_ALPHA;
	BlendFactor dstAlphaBlendFactor = BlendFactor::ONE_MINUS_SRC_ALPHA;
	BlendOperation alphaBlendOp = BlendOperation::ADD;
	uint32_t colorWriteMask = 0xF;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERCOLORBLEND_H_ */
