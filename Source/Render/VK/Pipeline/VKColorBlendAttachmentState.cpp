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

void ColorBlendAttachmentState::SetColor(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation)
{
	this->srcColorBlendFactor = ColorBlendAttachmentState::ConvertBlendFactor(src);
	this->dstColorBlendFactor = ColorBlendAttachmentState::ConvertBlendFactor(dst);
	this->colorBlendOp = ColorBlendAttachmentState::ConverBlendOperation(operation);
}

void ColorBlendAttachmentState::SetAlpha(Render::BlendFactor src, Render::BlendFactor dst, Render::BlendOperation operation)
{
	this->srcAlphaBlendFactor = ColorBlendAttachmentState::ConvertBlendFactor(src);
	this->dstAlphaBlendFactor = ColorBlendAttachmentState::ConvertBlendFactor(dst);
	this->alphaBlendOp = ColorBlendAttachmentState::ConverBlendOperation(operation);
}

VkBlendFactor ColorBlendAttachmentState::ConvertBlendFactor(Render::BlendFactor factor)
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

VkBlendOp ColorBlendAttachmentState::ConverBlendOperation(Render::BlendOperation operaion)
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
