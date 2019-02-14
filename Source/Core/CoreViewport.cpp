/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include "CoreViewport.h"

#include "RenderSwapChain.h"
#include "RenderImage.h"
#include "RenderContext.h"

#include <cassert>

namespace Core
{

Viewport::Viewport(void)
{
}

Viewport::~Viewport(void)
{
	mSwapChain = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::Initialize(Render::SwapChain* chain)
{
	mSwapChain = chain;
}

void Viewport::CreateDepthStencil(const Render::Extent2& extent)
{
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
