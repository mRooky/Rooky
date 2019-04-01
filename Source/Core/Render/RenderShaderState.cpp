/*
 * RenderShaderState.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "RenderShaderState.h"
#include "RenderShader.h"

#include <cassert>
#include <algorithm>

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
		bool result = (type == shader->GetType());
		if (true == result)
		{
			return shader;
		}
	}
	return nullptr;
}

bool ShaderState::operator==(const ShaderState& other) const
{
	assert(mShaders.size() > 0);
	if (mShaders.size() == other.mShaders.size())
	{
		const size_t count = mShaders.size();
		for (size_t index = 0; index < count; ++index)
		{
			const Shader* inter = mShaders.at(index);
			const Shader* outer = other.mShaders.at(index);
			if (inter != outer)
			{
				return false;
			}
		}
		return true;
	}
	return false;
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
