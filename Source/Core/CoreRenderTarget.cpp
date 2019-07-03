/*
 * CoreTarget.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreRenderTarget.h"
#include "CoreSystem.h"

#include "GHI/GHIDevice.h"
#include "GHI/GHIFactory.h"
#include "GHI/GHIImage.h"

#include <cassert>
#include <iostream>

namespace Core
{

RenderTarget::RenderTarget(System& system)
{
	mSystem = &system;
}

RenderTarget::~RenderTarget(void)
{
}

void RenderTarget::Create(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage)
{
	assert(mResource == nullptr);
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	mResource = factory->CreateImage();
	static_cast<GHI::Image*>(mResource)->Create(layout, usage);
}

const GHI::ImageLayout& RenderTarget::GetLayout(void) const
{
	assert(mResource != nullptr);
	GHI::Image* image = static_cast<GHI::Image*>(mResource);
	const GHI::ImageLayout& layout = image->GetLayout();
	return layout;
}

} /* namespace Core */
