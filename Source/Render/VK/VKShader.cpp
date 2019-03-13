/*
 * VKShader.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKShader.h"
#include "VKContext.h"

#include "VulkanShaderModule.h"
#include "VulkanInline.h"

#include <iostream>
#include <cassert>

namespace VK
{

Shader::Shader(Context* context):
		Render::Shader(context)
{
}

Shader::~Shader(void)
{
	Vulkan::Release(mShader);
}

void Shader::Create(Render::ShaderStage stage, const char* file)
{
	mStage = stage;
	std::vector<char> code = Vulkan::ShaderModule::GetSpirVString(file);
	if (code.size() > 0)
	{
		auto device = StaticCast(mContext)->GetVulkanDevice();
		mShader = Vulkan::ShaderModule::New(device);
		mShader->Create(code.size(), code.data());
	}
	else
	{
		std::cerr << "Create Shader Error !" << std::endl;
		std::cerr << "Shader File : " << file << std::endl;
	}
}

VkShaderStageFlagBits Shader::ConvertStage(Render::ShaderStage stage)
{
	switch(stage)
	{
	case Render::ShaderStage::SHADER_STAGE_VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case Render::ShaderStage::SHADER_STAGE_HULL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case Render::ShaderStage::SHADER_STAGE_DOMAIN:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case Render::ShaderStage::SHADER_STAGE_GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case Render::ShaderStage::SHADER_STAGE_FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case Render::ShaderStage::SHADER_STAGE_COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	default:
		assert(false);
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	}
}

} /* namespace VK */
