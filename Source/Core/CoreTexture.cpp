/*
 * CoreTexture.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTexture.h"
#include "CoreTextureManager.h"
#include "CoreSystem.h"

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIImage.h"

#include <cassert>
#include <iostream>

namespace Core
{

Texture::Texture(TextureManager* manager):
		mManager(manager)
{
	assert(mManager != nullptr);
}

Texture::~Texture(void)
{
	mSampler = nullptr;
	std::cout << "Destroy Texture : " << mName << std::endl;
}

void Texture::Create(const GHI::ImageLayout& layout, const GHI::UsageType& usage)
{
	assert(mResource == nullptr);
	auto system = mManager->GetSystem();
	auto device = system->GetDevice();
	auto factory = device->GetFactory();
	mResource = factory->CreateImage();
	static_cast<GHI::Image*>(mResource)->Create(layout, usage);
	const Math::Extent3Di& extent = layout.GetExtent();
	std::cout << "Image Width " << extent.width << std::endl;
	std::cout << "Image Height " << extent.height << std::endl;
}

void Texture::Update(uint32_t index, uint32_t mipmap, const void* src)
{
	assert(mResource != nullptr);
	static_cast<GHI::Image*>(mResource)->Upload(index, mipmap, src);
}

} /* namespace Core */
