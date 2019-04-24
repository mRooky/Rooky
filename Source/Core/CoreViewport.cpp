/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include "GHICommandList.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIImage.h"
#include "CoreViewport.h"
#include "CoreSystem.h"
#include "CoreThread.h"
#include "CoreScene.h"

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

void Viewport::Create(const Math::Rect2Di& rect)
{
	mViewport = rect;
	assert(rect.IsValid());
}

void Viewport::CreateThread(uint32_t count)
{
	System* system = mParent->GetSystem();
	mThread = new Core::Thread(system);
	mThread->Create(count);
}

void Viewport::Draw(void)
{
	assert(mThread != nullptr);

	Math::Rect2Di area = mViewport.GetExtent();
	Math::Rect2Di scissor = area;

	GHI::CommandList* command = mThread->GetCommandList(0);
	command->Begin();
	command->SetScissor(0, 1, &scissor);
	command->SetViewport(0, 1, &mViewport);
	command->End();
}

void Viewport::CreateDepthStencil(const Math::Extent2Di& extent)
{
	assert(mDepthStencil == nullptr);
	System* system = mParent->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::ImageLayout image_layout = {};
	image_layout.SetType(GHI::ImageType::IMAGE_TYPE_2D);
	image_layout.SetExtent(extent);
	image_layout.SetFormat(device->GetBestDepthStencilFormat());

	GHI::UsageType image_usage = {};
	image_usage.type = GHI::ResourceType::RESOURCE_TYPE_IMAGE;
	image_usage.depthStencil = TRUE;

	mDepthStencil = device->GetFactory()->CreateImage();
	mDepthStencil->Create(image_layout, image_usage);
}

} /* namespace Core */
