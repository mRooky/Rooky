/*
 * VKShaderStageCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKShaderStageCreateInfo.h"

#include "VulkanPipeline.h"

namespace VK
{

ShaderStageCreateInfo::ShaderStageCreateInfo(void)
{
	*static_cast<VkPipelineShaderStageCreateInfo*>(this) = Vulkan::Pipeline::ShaderStageCreateInfo();
}

ShaderStageCreateInfo::~ShaderStageCreateInfo(void)
{
}

} /* namespace VK */
