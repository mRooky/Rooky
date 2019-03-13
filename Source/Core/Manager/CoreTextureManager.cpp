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

namespace Core
{

TextureManager::TextureManager(System* system):
		Object(system)
{
}

TextureManager::~TextureManager(void)
{
	Util::Release(mTextures);
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
