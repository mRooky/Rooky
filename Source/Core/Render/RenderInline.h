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

static inline ImageLayout CreateImageLayout(const Render::Extent3Di& extent, Render::Format format)
{
	Render::ImageLayout image_layout = {};
	image_layout.extent = extent;
	image_layout.format = format;
	image_layout.type = Render::ImageType::IMAGE_TYPE_2D;
	return image_layout;
}

static inline size_t GetIndexTypeSize(IndexType type)
{
	switch(type)
	{
	case IndexType::INDEX_TYPE_U16:
		return 2;
	case IndexType::INDEX_TYPE_U32:
		return 4;
	default:
		assert(false);
		return 0;
	}
}

static inline const char* GetIndexTypeName(IndexType type)
{
	switch(type)
	{
	case IndexType::INDEX_TYPE_U16:
		return "INDEX_TYPE_U16";
	case IndexType::INDEX_TYPE_U32:
		return "INDEX_TYPE_U32";
	default:
		assert(false);
		return "Unknown";
	}
}

}

#endif /* SOURCE_CORE_RENDER_RENDERINLINE_H_ */
