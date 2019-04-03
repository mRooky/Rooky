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
#include <iostream>

namespace Core
{

Texture::Texture(TextureManager* manager):
		Target(manager)
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
	static_cast<Render::Image*>(mResource)->Upload(index, mipmap, src);
}

} /* namespace Core */
