/*
 * VKShaderStageCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanShaderStageInfo.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace Vulkan
{

ShaderStageInfo::ShaderStageInfo(void)
{
	*static_cast<VkPipelineShaderStageCreateInfo*>(this) = Vulkan::Pipeline::ShaderStageCreateInfo();
}

ShaderStageInfo::~ShaderStageInfo(void)
{
}

} /* namespace VK */
