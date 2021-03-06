/*
 * RenderLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERLAYOUT_H_
#define SOURCE_CORE_GHI_RENDERLAYOUT_H_

#include "GHIImageType.h"
#include "GHIFormat.h"

#include "../Math/MathExtent3.h"
#include <vector>

namespace GHI
{

class ImageLayout
{
public:
	ImageLayout(void) {};
	~ImageLayout(void) {};

public:
	inline void SetType(ImageType type)
	{
		mType = type;
	}

	inline void SetFormat(Format format)
	{
		mFormat = format;
	}

	inline void SetClearColor(uint32_t color)
	{
		mClearColor = color;
	}

	inline void SetExtent(const Math::Extent2Di& extent)
	{
		mExtent = extent;
	}

	inline void SetExtent(const Math::Extent3Di& extent)
	{
		mExtent = extent;
	}

public:
	inline uint32_t GetArray(void) const
	{
		return mArray;
	}

	inline uint32_t GetMipmap(void) const
	{
		return mMipmap;
	}

public:
	inline ImageType GetType(void) const
	{
		return mType;
	}

	inline Format GetFormat(void) const
	{
		return mFormat;
	}

	inline uint32_t GetClearColor(void) const
	{
		return mClearColor;
	}

	inline const Math::Extent3Di& GetExtent(void) const
	{
		return mExtent;
	}

protected:
	uint32_t mArray = 1;
	uint32_t mMipmap = 1;
	uint32_t mSamples = 1;
	Math::Extent3Di mExtent = {};

protected:
	uint32_t mClearColor = 0;

protected:
	Format mFormat = Format::UNDEFINED;
	ImageType mType = ImageType::IT_UNKNOWN;
};

}

#endif /* SOURCE_CORE_GHI_RENDERLAYOUT_H_ */
