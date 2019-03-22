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
#include "RenderFactory.h"

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
	mSwapChain = context->GetFactory()->CreateSwapChain();
	mSwapChain->Create(window);
}

void Viewport::CreateDepthStencil(const Render::Extent2D& extent)
{
	assert(mSwapChain != nullptr);
	assert(mDepthStencil == nullptr);

	Render::Context* context = mSwapChain->GetContext();
	Render::ImageLayout image_layout = {};

	image_layout.type = Render::ImageType::IMAGE_TYPE_2D;
	image_layout.extent = { extent.width, extent.height, 1 };
	image_layout.format = context->GetBestDepthStencilFormat();

	auto image_usage = Render::ResourceUsage::GetImageUsage(false);
	image_usage.imageUsage.DepthStencil = 1;

	mDepthStencil = context->GetFactory()->CreateImage();
	mDepthStencil->Create(image_layout, image_usage);
}

} /* namespace Core */
