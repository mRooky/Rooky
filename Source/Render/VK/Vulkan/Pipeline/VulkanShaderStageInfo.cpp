/*
 * VKShaderStageCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanShaderStageInfo.h"
#include <cassert>

namespace Vulkan
{

ShaderStageInfo::ShaderStageInfo(void)
{
	this->sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	this->pNext = nullptr;
	this->pSpecializationInfo = nullptr;
	this->flags = 0;
	this->stage = VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM;
	this->pName = "main";
}

ShaderStageInfo::~ShaderStageInfo(void)
{
}

} /* namespace VK */
