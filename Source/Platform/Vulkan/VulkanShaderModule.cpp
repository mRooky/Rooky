/*
 * VulkanShaderModule.cpp
 *
 *  Created on: Aug 28, 2018
 *      Author: rookyma
 */

#include "VulkanShaderModule.h"
#include "VulkanDevice.h"
#include "VulkanPipeline.h"
#include <cassert>
#include <fstream>

namespace Vulkan
{

ShaderModule::ShaderModule(Device* device):
		DeviceObject(device)
{
}

ShaderModule::~ShaderModule(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyShaderModule(device, m_shaderModule, nullptr);
	m_shaderModule = VK_NULL_HANDLE;
}

VkResult ShaderModule::Create(size_t size, const void* code)
{
	VkShaderModuleCreateInfo shader_modult_create_info = ShaderModule::CreateInfo();
	shader_modult_create_info.codeSize = size;
	shader_modult_create_info.pCode = reinterpret_cast<const uint32_t*>(code);
	return Create(&shader_modult_create_info);
}

VkResult ShaderModule::Create(const VkShaderModuleCreateInfo* info)
{
	mResult = vkCreateShaderModule(mDevice->GetHandle(), info, nullptr, &m_shaderModule);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkPipelineShaderStageCreateInfo ShaderModule::GetStageInfo(VkShaderStageFlagBits flag)
{
	VkPipelineShaderStageCreateInfo stage_create_info = Pipeline::ShaderStageCreateInfo();
	stage_create_info.stage = flag;
	stage_create_info.module = m_shaderModule;
	return stage_create_info;
}

VkShaderModuleCreateInfo ShaderModule::CreateInfo(void)
{
	VkShaderModuleCreateInfo shader_module_create_info = {};
	shader_module_create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	shader_module_create_info.pNext = nullptr;
	shader_module_create_info.flags = 0;
	shader_module_create_info.codeSize = 0;
	shader_module_create_info.pCode = nullptr;
	return shader_module_create_info;
}

std::vector<char> ShaderModule::GetSpirVString(const char* file)
{
	std::ifstream ios(file, std::ios::binary);
	std::vector<char> spir_v_code;
	if (ios.is_open())
	{
		ios.seekg(0, std::ios::end);
		size_t size = static_cast<size_t>(ios.tellg());
		ios.seekg(0, std::ios::beg);
		spir_v_code.resize(size);
		ios.read(spir_v_code.data(), size);
		ios.close();
	}
	return spir_v_code;
}

} /* namespace Vulkan */
