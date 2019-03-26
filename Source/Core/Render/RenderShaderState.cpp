/*
 * RenderShaderState.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "RenderShaderState.h"
#include "RenderShader.h"

#include <cassert>

namespace Render
{

ShaderState::ShaderState(void)
{
}

ShaderState::~ShaderState(void)
{
	mShaders.clear();
}

void ShaderState::SetShader(Shader* shader)
{
	ShaderType type = shader->GetType();
	if (nullptr == GetShader(type))
	{
		mShaders.push_back(shader);
	}
	else
	{
		assert(false);
	}
}

Shader* ShaderState::GetShader(ShaderType type) const
{
	for (auto shader : mShaders)
	{
		if (type == shader->GetType())
		{
			return shader;
		}
	}
	return nullptr;
}

} /* namespace Render */
