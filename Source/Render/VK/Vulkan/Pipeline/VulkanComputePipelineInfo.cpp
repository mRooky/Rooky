/*
 * VulkanComputePipelineInfo.cpp
 *
 *  Created on: Feb 21, 2019
 *      Author: rookyma
 */

#include "VulkanComputePipelineInfo.h"
#include "VulkanPipelineLayout.h"
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
	m_createInfo.layout = layout->GetHandle();
}

} /* namespace Vulkan */
