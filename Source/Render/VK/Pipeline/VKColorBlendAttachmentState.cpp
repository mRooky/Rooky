/*
 * VKColorBlendAttachmentState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKColorBlendAttachmentState.h"

#include <cassert>

namespace VK
{

ColorBlendAttachmentState::ColorBlendAttachmentState(void)
{

}

ColorBlendAttachmentState::~ColorBlendAttachmentState(void)
{
}

VkBlendFactor ColorBlendAttachmentState::Convert(Render::BlendFactor factor)
{
	switch(factor)
	{
	case Render::BlendFactor::BLEND_FACTOR_ZERO:
		return VK_BLEND_FACTOR_ZERO;
	case Render::BlendFactor::BLEND_FACTOR_ONE:
		return VK_BLEND_FACTOR_ONE;
	case Render::BlendFactor::BLEND_FACTOR_SRC_COLOR:
		return VK_BLEND_FACTOR_SRC_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_DST_COLOR:
		return VK_BLEND_FACTOR_DST_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_SRC_ALPHA:
		return VK_BLEND_FACTOR_SRC_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_DST_ALPHA:
		return VK_BLEND_FACTOR_DST_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_CONSTANT_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_SRC_ALPHA_SATURATE:
		return VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
	default:
		assert(false);
		return VK_BLEND_FACTOR_ZERO;
	}
}

VkBlendOp ColorBlendAttachmentState::Convert(Render::BlendOperation operaion)
{
	switch(operaion)
	{
	case Render::BlendOperation::BLEND_OPERATION_ADD:
		return VK_BLEND_OP_ADD;
	case Render::BlendOperation::BLEND_OPERATION_SUBTRACT:
		return VK_BLEND_OP_SUBTRACT;
	case Render::BlendOperation::BLEND_OPERATION_REVERSE_SUBTRACT:
		return VK_BLEND_OP_REVERSE_SUBTRACT;
	case Render::BlendOperation::BLEND_OPERATION_MIN:
		return VK_BLEND_OP_MIN;
	case Render::BlendOperation::BLEND_OPERATION_MAX:
		return VK_BLEND_OP_MAX;
	default:
		assert(false);
		return VK_BLEND_OP_ADD;
	}
}

} /* namespace VK */
