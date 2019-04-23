/*
 * CoreTexture.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "GHIImage.h"
#include "CoreTexture.h"
#include "CoreTextureManager.h"

#include <cassert>
#include <iostream>

namespace Core
{

Texture::Texture(TextureManager* manager):
		RenderTarget(manager)
{
}

Texture::~Texture(void)
{
	mSampler = nullptr;
	std::cout << "Destroy Texture : " << mName << std::endl;
}

void Texture::Update(uint32_t index, uint32_t mipmap, const void* src)
{
	assert(mResource != nullptr);
	static_cast<GHI::Image*>(mResource)->Upload(index, mipmap, src);
}

} /* namespace Core */
