/*
 * VKShader.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKShader.h"
#include "VulkanShaderModule.h"
#include "VulkanInline.h"
#include "VKDevice.h"

#include "UtilityString.h"

#include <iostream>
#include <cassert>

namespace VK
{

Shader::Shader(Device* device):
		Render::Shader(device)
{
}

Shader::~Shader(void)
{
	Vulkan::Release(mShader);
	std::cout << "Destroy Shader : " << mName << std::endl;
}

void Shader::Create(const char* file)
{
	std::vector<char> code = Vulkan::ShaderModule::GetSpirVString(file);
	if (code.size() > 0)
	{
		mName = Utility::GetFileName(file);
		mType = Render::Shader::GetShaderType(file);
		mStage = Render::Shader::GetShaderStage(file);
		std::cout << "Create Shader File : " << file << std::endl;
		CreateVulkanShader(code.size(), code.data());
	}
	else
	{
		std::cerr << "Create Shader Error !" << std::endl;
		std::cerr << "Shader File : " << file << std::endl;
	}
}

void Shader::CreateVulkanShader(size_t size, const void* data)
{
	assert(size > 0);
	auto vulkan_device = static_cast<Device*>(mDevice)->GetVulkanDevice();
	mShader = Vulkan::ShaderModule::New(vulkan_device);
	mShader->Create(size, data);
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