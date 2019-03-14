/*
 * CoreTextureManagerh.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "CoreTextureManager.h"
#include "CoreTexture.h"

#include "UtilRelease.h"

#include <cstring>
#include <cassert>
#include <iostream>

namespace Core
{

TextureManager::TextureManager(System* system):
		Object(system)
{
}

TextureManager::~TextureManager(void)
{
	std::cout << "Release Texture ..." << std::endl;
	Util::Release(mTextures);
	std::cout << "All Textures Released" << std::endl;
}

Texture* TextureManager::GetTexture(const char* name)
{
	assert(name != nullptr);
	Texture* texture = nullptr;
	for (auto tex : mTextures)
	{
		const char* tex_name = tex->GetName();
		if (std::strcmp(tex_name, name) == 0)
		{
			texture = tex;
			break;
		}
	}
	return texture;
}

Texture* TextureManager::CreateTexture(void)
{
	Texture* texture = new Texture(this);
	mTextures.push_back(texture);
	return texture;
}

} /* namespace Core */
