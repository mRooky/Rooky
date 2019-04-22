/*
 * CoreSystem.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "GHIDefine.h"
#include "GHIDevice.h"
#include "GHIInline.h"
#include "CoreSystem.h"

#include "CoreMeshManager.h"
#include "CoreTextureManager.h"
#include "CoreBindingManager.h"
#include "CorePipelineManager.h"

#include <cassert>

namespace Core
{

System::System(void)
{
}

System::~System(void)
{
	delete mMeshManager;
	mMeshManager = nullptr;
	delete mTextureManager;
	mTextureManager = nullptr;
	delete mBindingManager;
	mBindingManager = nullptr;
	delete mPipelineManager;
	mPipelineManager = nullptr;
	GHI::DestroyDevice(mDevice);
}

void System::Create(void)
{
	mDevice = GHI::CreateDevice();
	assert(mDevice != nullptr);
	mDevice->Create();
	mMeshManager = new MeshManager(this);
	mTextureManager = new TextureManager(this);
	mBindingManager = new BindingManager(this);
	mPipelineManager = new PipelineManager(this);
}

} /* namespace Core */
