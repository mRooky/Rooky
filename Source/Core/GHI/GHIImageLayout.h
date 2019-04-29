/*
 * RenderLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERLAYOUT_H_
#define SOURCE_CORE_GHI_RENDERLAYOUT_H_

#include "GHIEnum.h"
#include "GHIFormat.h"
#include "MathExtent3.h"
#include "MathDefine.h"
#include <vector>

namespace GHI
{

class ImageLayout
{
public:
	ImageLayout(void) = default;
	~ImageLayout(void) = default;

public:
	inline void SetType(ImageType type) { mType = type; }
	inline void SetFormat(Format format) { mFormat = format; }
	inline void SetClearColor(uint32_t color) { mClearColor = color; }
	inline void SetExtent(const Math::Extent2Di& extent) { mExtent = extent; }
	inline void SetExtent(const Math::Extent3Di& extent) { mExtent = extent; }

public:
	inline ImageType GetType(void) const { return mType; }
	inline Format GetFormat(void) const { return mFormat; }
	inline uint32_t GetClearColor(void) const { return mClearColor; }
	inline const Math::Extent3Di& GetExtent(void) const { return mExtent; }

public:
	uint32_t array = 1;
	uint32_t mipmap = 1;
	uint32_t samples = 1;
	Math::Extent3Di mExtent = {};

public:
	uint32_t mClearColor = 0;

public:
	Format mFormat = Format::FORMAT_UNDEFINED;
	ImageType mType = ImageType::IMAGE_TYPE_UNKNOWN;
};

}

#endif /* SOURCE_CORE_GHI_RENDERLAYOUT_H_ */
