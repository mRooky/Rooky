/*
 * CoreTextureManagerh.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */
#include "CoreTextureManager.h"
#include "../GHI/GHIDefine.h"
#include "../GHI/GHIDevice.h"
#include "../GHI/GHIFactory.h"
#include "../GHI/GHISampler.h"
#include "../Utility/UtilityRelease.h"
#include "../Kernel/KernelFileUtility.h"
#include "../CoreTexture.h"
#include "../CoreSystem.h"

#include <cstring>
#include <cassert>
#include <iostream>

namespace Core
{

TextureManager::TextureManager(System* system):
		Interface(system)
{
}

TextureManager::~TextureManager(void)
{
	size_t count = 0;
	std::cout << "Release Texture ..." << std::endl;
	count = mTextures.size();
	Utility::Release(mTextures);
	std::cout << count << " Texture(s) Released ! " << std::endl;

	std::cout << "Release Sampler ..." << std::endl;
	count = mSamplers.size();
	Utility::Release(mSamplers);
	std::cout << count << " Sampler(s) Released !" << std::endl;
}

Texture* TextureManager::CreateTexture1D(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture2D(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	std::string file_string = name;
	std::string file_name = Kernel::GetFileName(file_string);
	Texture* texture = GetTexture(file_name.c_str());
	if (texture == nullptr)
	{
		GHI::ImageLayout layout = {};
		layout.SetExtent(extent);
		layout.SetFormat(format);
		layout.SetType(GHI::ImageType::IT_2D);

		GHI::ResourceUsage usage = {};
		usage.memoryType.write = TRUE;
		usage.imageUsage.sampledImage = TRUE;

		texture = CreateTexture();
		texture->SetName(file_name.c_str());
		texture->Create(layout, usage);
	}
	assert(texture != nullptr);
	return texture;
}

Texture* TextureManager::CreateTexture3D(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture1DArray(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTexture2DArray(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTextureCube(const char* name, const Math::Extent3Di& extent, GHI::Format format)
{
	assert(false);
	return nullptr;
}

Texture* TextureManager::CreateTextureCubeArray(const char* name, const Math::Extent3Di& extent, GHI::Format format)
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

GHI::Sampler* TextureManager::CreateSampler(void)
{
	GHI::Device* device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	GHI::Sampler* sampler = factory->CreateSampler();
	mSamplers.push_back(sampler);
	return sampler;
}

} /* namespace Core */
