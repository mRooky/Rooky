/*
 * RenderLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERLAYOUT_H_
#define SOURCE_CORE_GHI_RENDERLAYOUT_H_

#include "GHIElement.h"
#include "GHIEnum.h"
#include "GHIFormat.h"
#include "MathExtent.h"
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

class VertexLayout
{
public:
	VertexLayout(void) = default;
	~VertexLayout(void) { mElements.clear(); }

public:
	void AppendElement(const Element& element);
	void SetElement(const std::vector<GHI::Element>& elements);

public:
	inline bool operator==(const VertexLayout& other) const { return mElements == other.mElements; }

public:
	inline const std::vector<Element>& GetElements(void) const { return mElements; }

public:
	inline size_t GetStride(void) const { return mStride; }
	inline bool IsValid(void) const { return mElements.size() > 0; }
	inline size_t GetElementCount(void) const { return mElements.size(); }
	inline const Element& GetElement(uint32_t index) const { return mElements.at(index); }

protected:
	size_t mStride = 0;
	std::vector<Element> mElements;
};

}

#endif /* SOURCE_CORE_GHI_RENDERLAYOUT_H_ */
