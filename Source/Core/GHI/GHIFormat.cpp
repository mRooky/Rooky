/*
 * RenderFormat.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: rookyma
 */

#include "GHIFormat.h"
#include <cassert>
#include <array>
#include <algorithm>

namespace GHI
{

size_t GetFormatSize(Format format)
{
	switch (format)
	{
	case Format::R32G32B32_SFLOAT:
		return 3 * sizeof(float);
	case Format::R32G32_SFLOAT:
		return 2 * sizeof(float);
	case Format::R32G32B32A32_SFLOAT:
		return 4 * sizeof(float);
	case Format::R8G8B8A8_UNORM:
		return 4 * sizeof(char);
	default:
		assert(false);
		break;
	}
	return 4;
}

bool IsDepthStencilFormat(Format format)
{
	static const std::array<Format, 7> ds_formats =
	{
			Format::D16_UNORM,
			Format::X8_D24_UNORM_PACK32,
			Format::D32_SFLOAT,
			Format::S8_UINT,
			Format::D16_UNORM_S8_UINT,
			Format::D24_UNORM_S8_UINT,
			Format::D32_SFLOAT_S8_UINT
	};

	auto it = std::find(ds_formats.begin(), ds_formats.end(), format);
	return it != ds_formats.end();
}

}
