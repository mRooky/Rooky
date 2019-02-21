/*
 * VKColorBlendAttachmentState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanColorBlendAttachmentState.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace Vulkan
{

ColorBlendAttachmentState::ColorBlendAttachmentState(void)
{
	BlendEnable(false);
}

ColorBlendAttachmentState::~ColorBlendAttachmentState(void)
{
}

void ColorBlendAttachmentState::BlendEnable(bool enabled)
{
	if (enabled)
	{
		this->blendEnable = VK_TRUE;
		this->srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		this->dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		this->colorBlendOp = VK_BLEND_OP_ADD;
		this->srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
		this->dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		this->alphaBlendOp = VK_BLEND_OP_ADD;
		this->colorWriteMask = VK_COLOR_COMPONENT_R_BIT
				| VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	}
	else
	{
		this->blendEnable = VK_FALSE;
		this->srcColorBlendFactor = VK_BLEND_FACTOR_SRC_COLOR;
		this->srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		this->dstColorBlendFactor = VK_BLEND_FACTOR_DST_COLOR;
		this->dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		this->colorBlendOp = VK_BLEND_OP_ADD;
		this->alphaBlendOp = VK_BLEND_OP_ADD;
		this->colorWriteMask = VK_COLOR_COMPONENT_R_BIT
				| VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	}
}

} /* namespace VK */
