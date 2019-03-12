/*
 * RenderLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERLAYOUT_HPP_
#define SOURCE_CORE_RENDER_RENDERLAYOUT_HPP_

#include "RenderEnum.h"
#include "RenderMath.h"
#include "RenderFormat.h"
#include "RenderUsage.h"

namespace Render
{

class ImageLayout
{
public:
	ImageLayout(void) = default;
	~ImageLayout(void) = default;

public:
	uint32_t mClearColor = 0;

public:
	uint32_t array = 1;
	Extent3 extent = {};
	uint32_t mipmap = 1;
	uint32_t samples = 1;
	ResourceUsage usage = {};

public:
	Format format = Format::FORMAT_UNDEFINED;
	ImageType type = ImageType::IMAGE_TYPE_UNKNOWN;
};

}

#endif /* SOURCE_CORE_RENDER_RENDERLAYOUT_HPP_ */
