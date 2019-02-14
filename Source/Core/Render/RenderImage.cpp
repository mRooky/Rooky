/*
 * RenderImage.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderImage.h"

#include <array>

namespace Render
{

Image::Image(Context* context):
		Resource(context)
{
}

Image::~Image(void)
{
}

bool Image::IsDepthStencilFormat(Format format)
{
	static const std::array<Format, 7> depth_stencil_formats =
	{
			Format::FORMAT_D16_UNORM,
			Format::FORMAT_X8_D24_UNORM_PACK32,
			Format::FORMAT_D32_SFLOAT,
			Format::FORMAT_S8_UINT,
			Format::FORMAT_D16_UNORM_S8_UINT,
			Format::FORMAT_D24_UNORM_S8_UINT,
			Format::FORMAT_D32_SFLOAT_S8_UINT
	};

	for (auto element : depth_stencil_formats)
	{
		if (element == format)
		{
			return true;
		}
	}
	return false;
}

} /* namespace Render */
