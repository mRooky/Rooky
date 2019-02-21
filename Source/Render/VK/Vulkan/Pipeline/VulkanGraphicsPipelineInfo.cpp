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

void GraphicsPipelineInfo::SetContent(PipelineLayout* layout, RenderPass* pass, uint32_t index)
{
	assert(pass != nullptr);
	assert(layout != nullptr);

	m_createInfo.layout = layout->GetHandle();
	m_createInfo.renderPass = pass->GetHandle();
	m_createInfo.subpass = index;
}

ShaderStageInfo* GraphicsPipelineInfo::CreateShaderStage(void)
{
	mShaderStages.push_back(ShaderStageInfo());
	m_createInfo.pStages = mShaderStages.data();
	m_createInfo.stageCount = mShaderStages.size();
	return &mShaderStages.back();
}

} /* namespace VK */
