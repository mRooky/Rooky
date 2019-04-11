/*
 * CoreShaderResource.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreShaderResource.h"
#include "CoreTexture.h"

namespace Core
{

ShaderResource::ShaderResource(void)
{
}

ShaderResource::~ShaderResource(void)
{
	mTextures.clear();
}

std::vector<Render::Binding> ShaderResource::GetBindings(void) const
{
	std::vector<Render::Binding> bindings;
	for (auto texture : mTextures)
	{
		Render::Binding binding;
		auto render_resource = texture->GetRenderResource();
		auto shader_stage = Render::ShaderStage::SHADER_STAGE_VERTEX;
		binding.SetResource(render_resource, shader_stage);
		bindings.push_back(binding);
	}
	return bindings;
}

} /* namespace Core */
