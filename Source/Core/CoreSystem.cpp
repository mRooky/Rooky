/*
 * CoreSystem.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreSystem.h"

#include "CoreBufferManager.h"
#include "CoreTextureManager.h"
#include "CoreBindingManager.h"
#include "CoreTexture.h"

#include "RenderInline.h"
#include "RenderDevice.h"
#include "RenderDefine.h"

#include <cassert>

namespace Core
{

System::System(void)
{
}

System::~System(void)
{
	delete mBufferManager;
	mBufferManager = nullptr;
	delete mTextureManager;
	mTextureManager = nullptr;
	delete mBindingManager;
	mBindingManager = nullptr;
	Render::DestroyDevice(mDevice);
}

void System::Create(void)
{
	mDevice = Render::CreateDevice();
	assert(mDevice != nullptr);
	mDevice->Create();
	mBufferManager = new BufferManager(this);
	mTextureManager = new TextureManager(this);
	mBindingManager = new BindingManager(this);
}

Texture* System::CreateTexture2D(const char* name, const Render::Extent3D& extent, Render::Format format)
{
	assert(mTextureManager != nullptr);

	Texture* texture = mTextureManager->GetTexture(name);
	if (texture == nullptr)
	{
		Render::ImageLayout image_layout = {};
		image_layout.extent = extent;
		image_layout.format = format;
		image_layout.type = Render::ImageType::IMAGE_TYPE_2D;

		auto image_usage = Render::ResourceUsage::GetImageUsage(false);
		image_usage.allocate.Destination = TRUE;
		image_usage.imageUsage.SampledImage = TRUE;

		texture = mTextureManager->CreateTexture();
		texture->SetName(name);
		texture->Create(image_layout, image_usage);
	}

	assert(texture != nullptr);
	return texture;
}

} /* namespace Core */
