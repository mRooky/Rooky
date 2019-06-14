/*
 * RenderShaderState.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "GHIShader.h"
#include "GHIShaderState.h"
#include <cassert>
#include <algorithm>

namespace GHI
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
		auto current = shader->GetType();
		if (current == type)
		{
			return shader;
		}
	}
	return nullptr;
}

bool ShaderState::operator==(const ShaderState& other) const
{
	assert(mShaders.size() > 0);
	return mShaders == other.mShaders;
}

ShaderState& ShaderState::operator=(const ShaderState& other)
{
	assert(other.mShaders.size() > 0);
	mShaders.clear();
	mShaders.resize(other.mShaders.size());
	std::copy(other.mShaders.begin(), other.mShaders.end(), mShaders.begin());
	return *this;
}

} /* namespace Render */
