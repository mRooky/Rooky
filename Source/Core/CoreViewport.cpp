/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include "CoreViewport.h"
#include "CoreSystem.h"
#include "CoreThread.h"
#include "CoreScene.h"

#include "RenderImage.h"
#include "RenderFactory.h"
#include "RenderDevice.h"

#include <cassert>

namespace Core
{

Viewport::Viewport(Scene* scene):
		mParent(scene)
{
	assert(mParent != nullptr);
}

Viewport::~Viewport(void)
{
	delete mThread;
	mThread = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::CreateThread(uint32_t count)
{
	System* system = mParent->GetSystem();
	mThread = new Core::Thread(system);
	mThread->Create(count);
}

void Viewport::CreateDepthStencil(const Render::Extent2Di& extent)
{
	assert(mDepthStencil == nullptr);
	System* system = mParent->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::ImageLayout image_layout = {};

	image_layout.type = Render::ImageType::IMAGE_TYPE_2D;
	image_layout.extent = { extent.width, extent.height, 1 };
	image_layout.format = device->GetBestDepthStencilFormat();

	Render::UsageType image_usage = {};
	image_usage.type = Render::ResourceType::RESOURCE_TYPE_IMAGE;
	image_usage.depthStencil = TRUE;

	mDepthStencil = device->GetFactory()->CreateImage();
	mDepthStencil->Create(image_layout, image_usage);
}

} /* namespace Core */
