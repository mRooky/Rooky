/*
 * VulkanComputePipelineInfo.cpp
 *
 *  Created on: Feb 21, 2019
 *      Author: rookyma
 */

#include "VulkanComputePipelineInfo.h"
#include "VulkanPipelineLayout.h"
#include "VulkanShaderModule.h"
#include <cassert>

namespace Vulkan
{

ComputePipelineInfo::ComputePipelineInfo(void)
{
	m_createInfo = {};
	m_createInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
}

ComputePipelineInfo::~ComputePipelineInfo(void)
{
}

void ComputePipelineInfo::SetLayout(PipelineLayout* layout)
{
	assert(layout != nullptr);
	m_pipelineLayout = layout;
	m_createInfo.layout = layout->GetHandle();
}

void ComputePipelineInfo::SetShader(ShaderModule* shader, const char* entry)
{
	assert(shader != nullptr);
	VkPipelineShaderStageCreateInfo& shader_stage = m_createInfo.stage;
	shader_stage.module = shader->GetHandle();
	shader_stage.pName = entry;
	shader_stage.stage = VK_SHADER_STAGE_COMPUTE_BIT;
}

} /* namespace Vulkan */
