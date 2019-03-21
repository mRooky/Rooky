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

#include "RenderContext.h"
#include "RenderInline.h"

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
	Render::DestroyContext(mContext);
}

void System::Create(void)
{
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Create();
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
		auto image_layout = CreateImageLayout(extent, format);
		texture = mTextureManager->CreateTexture();
		texture->SetName(name);
		texture->Create(image_layout);
	}

	assert(texture != nullptr);
	return texture;
}

} /* namespace Core */
