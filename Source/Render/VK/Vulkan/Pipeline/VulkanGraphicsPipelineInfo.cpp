/*
 * VKGraphicsPipelineInfo.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#include "VulkanGraphicsPipelineInfo.h"
#include "VulkanPipeline.h"
#include "VulkanRenderPass.h"
#include "VulkanPipelineLayout.h"

#include <cassert>

namespace Vulkan
{

GraphicsPipelineInfo::GraphicsPipelineInfo(void)
{
	*static_cast<VkGraphicsPipelineCreateInfo*>(this) = Vulkan::Pipeline::GraphicsCreateInfo();
	this->pStages = &mShaderStage;
	this->pVertexInputState = &mVertexInputState;
	this->pInputAssemblyState = &mInputAssemblyState;
	this->pViewportState = &mViewportState;
	this->pRasterizationState = &mRasterizationState;
	this->pMultisampleState = &mMultisampleState;
	this->pDepthStencilState = &mDepthStencilState;
	this->pColorBlendState = &mColorBlendState;
	this->pDynamicState = &mDynamicState;
}

GraphicsPipelineInfo::~GraphicsPipelineInfo(void)
{
}

void GraphicsPipelineInfo::SetContent(PipelineLayout* layout, RenderPass* pass, uint32_t index)
{
	assert(pass != nullptr);
	assert(layout != nullptr);

	this->layout = layout->GetHandle();
	this->renderPass = pass->GetHandle();
	this->subpass = index;
}

} /* namespace VK */
