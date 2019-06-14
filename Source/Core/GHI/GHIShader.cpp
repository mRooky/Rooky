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

ShaderType Shader::GetShaderType(const Kernel::String& file)
{
	static const std::map<std::string, ShaderType> stage_map =
	{
		{"vert", ShaderType::VERTEX},
		{"tesc", ShaderType::HULL},
		{"tese", ShaderType::DOMAIN},
		{"geom", ShaderType::GEOMETRY},
		{"frag", ShaderType::FRAGMENT},
		{"comp", ShaderType::COMPUTE}
	};
	std::string file_name = file;
	std::string file_type = Kernel::GetFileType(file);
	auto iterator = stage_map.find(file_type);
	assert(iterator != stage_map.end());
	ShaderType type = iterator->second;
	return type;
}

ShaderStage Shader::GetShaderStage(const Kernel::String& file)
{
	static const std::map<std::string, ShaderStage> stage_map =
	{
		{"vert", ShaderStage::VERTEX},
		{"tesc", ShaderStage::HULL},
		{"tese", ShaderStage::DOMAIN},
		{"geom", ShaderStage::GEOMETRY},
		{"frag", ShaderStage::FRAGMENT},
		{"comp", ShaderStage::COMPUTE}
	};
	std::string file_name = file;
	std::string file_type = Kernel::GetFileType(file);
	auto iterator = stage_map.find(file_type);
	assert(iterator != stage_map.end());
	ShaderStage stage = iterator->second;
	return stage;
}

} /* namespace Render */
