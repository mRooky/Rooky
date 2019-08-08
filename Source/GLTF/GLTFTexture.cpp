/*
 * =====================================================================================
 *
 *       Filename:  GLTFTexture.cpp
 *
 * =====================================================================================
 */
#include "GLTFTexture.h"
#include "GLTFManager.h"
#include "../Core/GHI/GHIImage.h"
#include "../Core/GHI/GHIDevice.h"
#include "../Core/GHI/GHIFactory.h"
#include <cassert>
#include <iostream>

namespace GLTF
{

Texture::Texture(Manager* manager):
	Resource(manager)
{
}

Texture::~Texture(void)
{
	delete mImage;
	mImage = nullptr;
}

void Texture::Create(const GHI::ImageLayout& layout, const GHI::MemoryUsage& usage)
{
	assert(mImage == nullptr);
	auto device = mManager->GetDevice();
	auto factory = device->GetFactory();
	mImage = factory->CreateImage();
	mImage->Create(layout, usage);
	const Math::Extent3Di& extent = layout.GetExtent();
	std::cout << "GLTF Create Image Width " << extent.width << std::endl;
	std::cout << "GLTF Create Image Height " << extent.height << std::endl;

}

}

