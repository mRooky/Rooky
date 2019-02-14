/*
 * RenderFormat.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: rookyma
 */

#include "RenderFormat.h"
#include <cassert>

namespace Render
{

size_t GetFormatSize(Format format)
{
	size_t size = 4;
	switch (format)
	{
	case Format::FORMAT_R32G32B32_SFLOAT:
		size = 3 * sizeof(float);
		break;
	case Format::FORMAT_R32G32_SFLOAT:
		size = 2 * sizeof(float);
		break;
	case Format::FORMAT_R32G32B32A32_SFLOAT:
		size = 4 * sizeof(float);
		break;
	default:
		assert(false);
		break;
	}
	return size;
}

}
