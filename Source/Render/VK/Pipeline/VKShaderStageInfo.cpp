/*
 * VKShaderStageCreateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKShaderStageInfo.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace VK
{

ShaderStageInfo::ShaderStageInfo(void)
{
	*static_cast<VkPipelineShaderStageCreateInfo*>(this) = Vulkan::Pipeline::ShaderStageCreateInfo();
}

ShaderStageInfo::~ShaderStageInfo(void)
{
}

VkShaderStageFlagBits ShaderStageInfo::Convert(Render::ShaderStage stage)
{
	switch(stage)
	{
	case Render::ShaderStage::SHADER_STAGE_VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case Render::ShaderStage::SHADER_STAGE_TESSELLATION_CONTROL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case Render::ShaderStage::SHADER_STAGE_TESSELLATION_EVALUATION:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case Render::ShaderStage::SHADER_STAGE_GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case Render::ShaderStage::SHADER_STAGE_FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case Render::ShaderStage::SHADER_STAGE_COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	case Render::ShaderStage::SHADER_STAGE_ALL_GRAPHICS:
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	default:
		assert(false);
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	}
}

} /* namespace VK */
