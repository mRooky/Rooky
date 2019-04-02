/*
 * CoreTextureManagerh.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "CoreTextureManager.h"
#include "CoreTexture.h"
#include "CoreSystem.h"

#include "RenderDevice.h"
#include "RenderFactory.h"
#include "RenderSampler.h"
#include "RenderDefine.h"

#include "UtilRelease.h"
#include "UtilString.h"

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
	size_t count = 0;
	std::cout << "Release Texture ..." << std::endl;
	count = mTextures.size();
	Util::Release(mTextures);
	std::cout << count << " Texture(s) Released ! " << std::endl;

	std::cout << "Release Sampler ..." << std::endl;
	count = mSamplers.size();
	Util::Release(mSamplers);
	std::cout << count << " Sampler(s) Released !" << std::endl;
}

Texture* TextureManager::CreateTexture1D(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture2D(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	std::string file_string = name;
	std::string file_name = Util::GetFileName(file_string);
	Texture* texture = GetTexture(file_name.c_str());
	if (texture == nullptr)
	{
		Render::ImageLayout image_layout = {};
		image_layout.extent = extent;
		image_layout.format = format;
		image_layout.type = Render::ImageType::IMAGE_TYPE_2D;

		auto image_usage = Render::ResourceUsage::GetImageUsage(false);
		image_usage.allocate.Destination = TRUE;
		image_usage.imageUsage.SampledImage = TRUE;

		texture = CreateTexture();
		texture->SetName(file_name.c_str());
		texture->Create(image_layout, image_usage);
	}
	assert(texture != nullptr);
	return texture;
}

Texture* TextureManager::CreateTexture3D(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture1DArray(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture2DArray(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTextureCube(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTextureCubeArray(const char* name, const Render::Extent3Di& extent, Render::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::GetTexture(const char* name)
{
	assert(name != nullptr);
	for (auto texture : mTextures)
	{
		const char* tex_name = texture->GetName();
		if (std::strcmp(tex_name, name) == 0)
		{
			return texture;
		}
	}
	return nullptr;
}

Texture* TextureManager::CreateTexture(void)
{
	Texture* texture = new Texture(this);
	mTextures.push_back(texture);
	return texture;
}

Render::Sampler* TextureManager::CreateSampler(void)
{
	Render::Device* device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::Sampler* sampler = factory->CreateSampler();
	mSamplers.push_back(sampler);
	return sampler;
}

} /* namespace Core */
