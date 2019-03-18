/*
 * CoreSystem.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreSystem.h"

#include "CoreBufferManager.h"
#include "CoreTextureManager.h"
#include "CoreResourceManager.h"
#include "CoreTexture.h"

#include "RenderContext.h"
#include "RenderLayout.hpp"

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
	delete mResourceManager;
	mResourceManager = nullptr;
	Render::DestroyContext(mContext);
}

void System::Create(void)
{
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Create();
	mBufferManager = new BufferManager(this);
	mTextureManager = new TextureManager(this);
	mResourceManager = new ResourceManager(this);
}

Texture* System::CreateTexture2D(const char* name, const Render::Extent3D& extent, Render::Format format)
{
	assert(mTextureManager != nullptr);

	Texture* texture = mTextureManager->GetTexture(name);
	if (texture == nullptr)
	{
		Render::ImageLayout image_layout = {};
		image_layout.extent = extent;
		image_layout.usage = Render::ResourceUsage::GetImageUsage(false);
		image_layout.usage.binding.SampledImage = 1;
		image_layout.format = format;
		image_layout.type = Render::ImageType::IMAGE_TYPE_2D;

		texture = mTextureManager->CreateTexture();
		texture->SetName(name);
		texture->Create(image_layout);
	}

	assert(texture != nullptr);
	return texture;
}

} /* namespace Core */
