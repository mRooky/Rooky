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

bool Image::IsDepthStencilFormat(Format format)
{
	static const std::array<Format, 7> ds_formats =
	{
			Format::FORMAT_D16_UNORM,
			Format::FORMAT_X8_D24_UNORM_PACK32,
			Format::FORMAT_D32_SFLOAT,
			Format::FORMAT_S8_UINT,
			Format::FORMAT_D16_UNORM_S8_UINT,
			Format::FORMAT_D24_UNORM_S8_UINT,
			Format::FORMAT_D32_SFLOAT_S8_UINT
	};

	auto it = std::find(ds_formats.begin(), ds_formats.end(), format);
	return it != ds_formats.end();
}

} /* namespace Render */
