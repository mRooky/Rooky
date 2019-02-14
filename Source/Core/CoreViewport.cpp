/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include "CoreViewport.h"
#include "CoreSystem.h"

#include "RenderSwapChain.h"
#include "RenderImage.h"
#include "RenderContext.h"

#include <cassert>

namespace Core
{

Viewport::Viewport(System* system):
		Object(system)
{
}

Viewport::~Viewport(void)
{
	delete mSwapChain;
	mSwapChain = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::Create(Platform::Window* window)
{
	auto context = mSystem->GetContext();
	mSwapChain = context->CreateSwapChain();
	mSwapChain->Create(window);
}

void Viewport::CreateDepthStencil(const Render::Extent2& extent)
{
	assert(mSwapChain != nullptr);
	assert(mDepthStencil == nullptr);

	Render::Context* context = mSwapChain->GetContext();
	Render::Format format = context->GetBestDepthStencilFormat();
	uint32_t flags = 0;
	flags |= static_cast<uint32_t>(Render::ImageUsageFlags::IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT);
	uint32_t usage = context->GetImageUsageFlag(flags, true, false);
	Render::Extent3 extent3 = { extent.width, extent.height, 1 };

	mDepthStencil = context->CreateImage();
	mDepthStencil->Create(format, extent3, usage);
}

} /* namespace Core */
