/*
 * RenderShaderState.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#include "RenderShaderState.h"
#include "RenderShader.h"

namespace Render
{

ShaderState::ShaderState(void)
{
}

ShaderState::~ShaderState(void)
{
}

void ShaderState::SetShader(Shader* shader)
{
	auto type = shader->GetType();
	size_t index = static_cast<size_t>(type);
	mShaderMask.set(index);
	mShaders.at(index) = shader;
}

} /* namespace Render */
