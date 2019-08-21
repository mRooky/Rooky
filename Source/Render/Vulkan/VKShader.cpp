/*
 * VKShader.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKShader.h"
#include "VKDevice.h"
#include "../../Platform/Vulkan/VulkanShaderModule.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Core/Kernel/KernelFileUtility.h"

#include <iostream>
#include <cassert>

namespace VK
{

Shader::Shader(Device* device):
		GHI::Shader(device)
{
}

Shader::~Shader(void)
{
	Vulkan::Release(mShader);
	std::cout << "Destroy Shader : " << mName << std::endl;
}

void Shader::Create(const std::string& file)
{
	std::vector<char> code = Vulkan::ShaderModule::GetSpirVString(file.c_str());
	if (code.size() > 0)
	{
		mName = Kernel::GetFileName(file);
		mType = GHI::Shader::GetShaderType(file);
		mStage = GHI::Shader::GetShaderStage(file);
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

VkShaderStageFlagBits Shader::ConvertStage(GHI::ShaderStage stage)
{
	switch(stage)
	{
	case GHI::ShaderStage::VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case GHI::ShaderStage::HULL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case GHI::ShaderStage::DOMAIN:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case GHI::ShaderStage::GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case GHI::ShaderStage::FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case GHI::ShaderStage::COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	default:
		assert(false);
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	}
}

} /* namespace VK */
