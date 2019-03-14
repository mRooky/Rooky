/*
 * CoreTexture.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTexture.h"
#include "CoreTextureManager.h"

#include "RenderImage.h"

#include <cassert>

namespace Core
{

Texture::Texture(TextureManager* manager):
		Target(manager)
{
}

Texture::~Texture(void)
{
	mSampler = nullptr;
}

void Texture::Update(uint32_t index, uint32_t mipmap, const void* src)
{
	assert(mImage != nullptr);
	mImage->Upload(index, mipmap, src);
}

} /* namespace Core */
