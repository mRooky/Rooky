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

void Shader::Create(const char* file)
{
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

} /* namespace VK */
