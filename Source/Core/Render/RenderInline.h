/*
 * RenderInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERINLINE_H_
#define SOURCE_CORE_RENDER_RENDERINLINE_H_

#include "RenderLayout.hpp"
#include <cstddef>
#include <cassert>

namespace Render
{

static inline uint32_t Bit(uint32_t pos)
{
	return 1u << pos;
}

static inline ImageLayout CreateImageLayout(const Render::Extent3D& extent, Render::Format format)
{
	Render::ImageLayout image_layout = {};
	image_layout.extent = extent;
	image_layout.usage = Render::ResourceUsage::GetImageUsage(false);
	image_layout.usage.allocate.Destination = 1;
	image_layout.usage.imageUsage.SampledImage = 1;
	image_layout.format = format;
	image_layout.type = Render::ImageType::IMAGE_TYPE_2D;
	return image_layout;
}

}

#endif /* SOURCE_CORE_RENDER_RENDERINLINE_H_ */
