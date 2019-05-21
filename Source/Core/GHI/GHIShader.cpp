/*
 * RenderShader.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#include "GHIShader.h"
#include "../Kernel/KernelFileUtility.h"
#include <cassert>
#include <map>

namespace GHI
{

Shader::Shader(Device* device):
		Object(device)
{
}

Shader::~Shader(void)
{
}

ShaderType Shader::GetShaderType(const char* file)
{
	static const std::map<std::string, ShaderType> stage_map =
	{
		{"vert", ShaderType::SHADER_TYPE_VERTEX},
		{"tesc", ShaderType::SHADER_TYPE_HULL},
		{"tese", ShaderType::SHADER_TYPE_DOMAIN},
		{"geom", ShaderType::SHADER_TYPE_GEOMETRY},
		{"frag", ShaderType::SHADER_TYPE_FRAGMENT},
		{"comp", ShaderType::SHADER_TYPE_COMPUTE}
	};
	std::string file_name = file;
	std::string file_type = Kernel::GetFileType(file);
	auto iterator = stage_map.find(file_type);
	assert(iterator != stage_map.end());
	ShaderType type = iterator->second;
	return type;
}

ShaderStage Shader::GetShaderStage(const char* file)
{
	static const std::map<std::string, ShaderStage> stage_map =
	{
		{"vert", ShaderStage::SHADER_STAGE_VERTEX},
		{"tesc", ShaderStage::SHADER_STAGE_HULL},
		{"tese", ShaderStage::SHADER_STAGE_DOMAIN},
		{"geom", ShaderStage::SHADER_STAGE_GEOMETRY},
		{"frag", ShaderStage::SHADER_STAGE_FRAGMENT},
		{"comp", ShaderStage::SHADER_STAGE_COMPUTE}
	};
	std::string file_name = file;
	std::string file_type = Kernel::GetFileType(file);
	auto iterator = stage_map.find(file_type);
	assert(iterator != stage_map.end());
	ShaderStage stage = iterator->second;
	return stage;
}

} /* namespace Render */
