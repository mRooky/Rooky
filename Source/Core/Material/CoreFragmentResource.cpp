/*
 * CoreFragmentResource.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#include "CoreFragmentResource.h"
#include "CoreTexture.h"

namespace Core
{

FragmentResource::FragmentResource(void)
{
}

FragmentResource::~FragmentResource(void)
{
	mTextures.clear();
}

ResourceBindSet FragmentResource::GetBindingSet(void) const
{
	ResourceBindSet binding_set;
	for (auto texture : mTextures)
	{
		auto render_resource = texture->GetRenderResource();
		auto shader_stage = GHI::ShaderStage::SHADER_STAGE_VERTEX;
		binding_set.PushResource(render_resource, shader_stage);
	}
	return binding_set;
}

} /* namespace Core */
