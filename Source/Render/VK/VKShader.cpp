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
		auto device = static_cast<Context*>(mContext)->GetDeviceVK();
		mShader = Vulkan::ShaderModule::New(device);
		mShader->Create(code.size(), code.data());
	}
	else
	{
		std::cerr << "Create Shader Error !" << std::endl;
		std::cerr << "Shader File : " << file << std::endl;
	}
}

ShaderStageInfo Shader::GetStageCreateInfo(void) const
{
	ShaderStageInfo stage_create_info = {};
	stage_create_info.SetContent(mShader->GetHandle(), mStage);
	return stage_create_info;
}

} /* namespace VK */
