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

Manager::Manager(void)
{
	mDevice = GHI::CreateDevice();
	assert(mDevice != nullptr);
	mDevice->Create();
}

Manager::~Manager(void)
{
	for (auto texture : mTextures)
	{
		delete texture;
	}
	mTextures.clear();
	GHI::DestroyDevice(mDevice);
}

}

