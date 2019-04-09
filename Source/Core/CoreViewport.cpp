/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */


#include <RenderDevice.h>
#include "CoreViewport.h"
#include "CoreSystem.h"

#include "RenderSwapChain.h"
#include "RenderImage.h"
#include "RenderFactory.h"

#include <cassert>

namespace Core
{

Viewport::Viewport(System* system):
		Interface(system)
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
	auto device = mSystem->GetDevice();
	mSwapChain = device->GetFactory()->CreateSwapChain();
	mSwapChain->Create(window);
}

void Viewport::CreateDepthStencil(const Render::Extent2Di& extent)
{
	assert(mSwapChain != nullptr);
	assert(mDepthStencil == nullptr);

	Render::Device* device = mSwapChain->GetDevice();
	Render::ImageLayout image_layout = {};

	image_layout.type = Render::ImageType::IMAGE_TYPE_2D;
	image_layout.extent = { extent.width, extent.height, 1 };
	image_layout.format = device->GetBestDepthStencilFormat();

	auto image_usage = Render::ResourceUsage::GetImageUsage(false);
	image_usage.imageUsage.DepthStencil = TRUE;

	mDepthStencil = device->GetFactory()->CreateImage();
	mDepthStencil->Create(image_layout, image_usage);
}

} /* namespace Core */
