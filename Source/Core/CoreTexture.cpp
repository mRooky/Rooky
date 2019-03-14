/*
 * CoreTexture.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTexture.h"
#include "CoreTextureManager.h"

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

void Texture::Create(const char* file, const Render::ImageLayout& layout)
{
	mName = file;
	Target::Create(layout);
}

} /* namespace Core */
