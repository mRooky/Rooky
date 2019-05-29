/*
 * VKGraphicsPipelineInfo.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#include "VulkanGraphicsPipelineInfo.h"
#include "../VulkanPipeline.h"
#include "../VulkanRenderPass.h"
#include "../VulkanPipelineLayout.h"

#include <cassert>

namespace Vulkan
{

GraphicsPipelineInfo::GraphicsPipelineInfo(void)
{
	mShaderStages.reserve(5);
	m_createInfo = Vulkan::Pipeline::GraphicsCreateInfo();
	m_createInfo.pStages = mShaderStages.data();
	m_createInfo.stageCount = mShaderStages.size();
	m_createInfo.pVertexInputState = mVertexInputStateInfo.CreateInfo();
	m_createInfo.pInputAssemblyState = mInputAssemblyStateInfo.CreateInfo();
	m_createInfo.pViewportState = mViewportStateInfo.CreateInfo();
	m_createInfo.pRasterizationState = mRasterizationStateInfo.CreateInfo();
	m_createInfo.pMultisampleState = mMultisampleStateInfo.CreateInfo();
	m_createInfo.pDepthStencilState = mDepthStencilStateInfo.CreateInfo();
	m_createInfo.pColorBlendState = mColorBlendStateInfo.CreateInfo();
	m_createInfo.pDynamicState = mDynamicStateInfo.CreateInfo();
}

GraphicsPipelineInfo::~GraphicsPipelineInfo(void)
{
}

VkPipelineShaderStageCreateInfo* GraphicsPipelineInfo::CreateShaderStage(void)
{
	auto shader_stage_create_info = Vulkan::Pipeline::ShaderStageCreateInfo();
	mShaderStages.push_back(shader_stage_create_info);
	m_createInfo.pStages = mShaderStages.data();
	m_createInfo.stageCount = mShaderStages.size();
	return &mShaderStages.back();
}

void GraphicsPipelineInfo::SetContent(PipelineLayout* layout)
{
	m_createInfo.layout = layout->GetHandle();
}

void GraphicsPipelineInfo::SetContent(RenderPass* pass, uint32_t index)
{
	m_createInfo.subpass = index;
	m_createInfo.renderPass = pass->GetHandle();
}

} /* namespace VK */
