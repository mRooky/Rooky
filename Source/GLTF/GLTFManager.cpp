/*
 * =====================================================================================
 *
 *       Filename:  GLTFManager.cpp
 *
 * =====================================================================================
 */
#include "GLTFManager.h"
#include "GLTFTexture.h"
#include "../Core/GHI/GHIDevice.h"
#include <cassert>

namespace GLTF
{

Manager::Manager(Render* render):
	mRender(render)
{
}

Manager::~Manager(void)
{
	mRender = nullptr;
	for (auto texture : mTextures)
	{
		delete texture;
	}
	mTextures.clear();
	GHI::DestroyDevice(mDevice);
}

void Manager::Init(void)
{
	mDevice = GHI::CreateDevice();
	assert(mDevice != nullptr);
	mDevice->Create();
}

}

