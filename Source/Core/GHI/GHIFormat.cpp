/*
 * RenderFormat.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: rookyma
 */

#include "GHIFormat.h"
#include <cassert>

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

}
