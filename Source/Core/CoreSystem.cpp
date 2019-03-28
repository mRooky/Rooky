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
#include "CorePipelineManager.h"

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
	delete mPipelineManager;
	mPipelineManager = nullptr;
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
	mPipelineManager = new PipelineManager(this);
}

} /* namespace Core */
