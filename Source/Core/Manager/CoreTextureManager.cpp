/*
 * CoreTextureManagerh.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "CoreTextureManager.h"
#include "CoreTexture.h"

#include "UtilRelease.h"

#include <string>
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

Texture* TextureManager::GetTexture(const char* file)
{
	Texture* texture = TextureFind(file);
	if (texture == nullptr)
	{
		texture = new Texture(this);
		mTextures.push_back(texture);
	}
	return texture;
}

Texture* TextureManager::TextureFind(const char* file) const
{
	std::string texture_name(file);
	for (auto texture : mTextures)
	{
		const char* name = texture->GetName();
		if (texture_name == name)
		{
			return texture;
		}
	}
	return nullptr;
}

} /* namespace Core */
