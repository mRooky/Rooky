/*
 * CoreFragmentResource.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#include "CoreFragmentResource.h"
#include "../CoreTexture.h"

namespace Core
{

FragmentResource::FragmentResource(void)
{
}

FragmentResource::~FragmentResource(void)
{
	mTextures.clear();
}

void FragmentResource::AppendTexture(Texture* texture)
{
	mTextures.push_back(texture);
	auto resource = texture->GetRenderResource();
	auto stage = GHI::ShaderStage::FRAGMENT;
	GHI::Binding binding;
	binding.SetResource(resource, stage);
	mBindings.push_back(binding);
}

} /* namespace Core */
