/*
 * RenderImage.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "GHIImage.h"
#include <array>
#include <cassert>
#include <algorithm>

namespace GHI
{

Image::Image(Device* device):
		Memory(device)
{
	mType = ResourceType::IMAGE;
}

Image::~Image(void)
{
}

bool Image::IsDepthStencil(void) const
{
	const auto& usage = mUsage.imageUsage;
	bool for_depth_stencil = usage.ForDepthStencil();
	if (true == for_depth_stencil)
	{
		Format format = mLayout.GetFormat();
		bool format_depth_stencil = IsDepthStencilFormat(format);
		return (true == format_depth_stencil);
	}
	return false;
}

size_t Image::GetLevelOffset(uint32_t level) const
{
	size_t offset = 0;
	assert(false);
	return offset;
}

Math::Extent3Di Image::GetLevelExtent(uint32_t level) const
{
	Math::Extent3Di extent = {};
	assert(false);
	return extent;
}

} /* namespace Render */
