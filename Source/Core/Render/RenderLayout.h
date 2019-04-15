/*
 * RenderLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERLAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERLAYOUT_H_

#include "RenderMath.h"
#include "RenderEnum.h"
#include "RenderFormat.h"
#include "RenderExtent.hpp"
#include "RenderElement.h"
#include <vector>

namespace Render
{

class ImageLayout
{
public:
	ImageLayout(void) = default;
	~ImageLayout(void) = default;

public:
	uint32_t array = 1;
	uint32_t mipmap = 1;
	uint32_t samples = 1;
	Extent3Di extent = {};

public:
	uint32_t mClearColor = 0;

public:
	Format format = Format::FORMAT_UNDEFINED;
	ImageType type = ImageType::IMAGE_TYPE_UNKNOWN;
};

class VertexLayout
{
public:
	VertexLayout(void) = default;
	~VertexLayout(void) { mElements.clear(); }

public:
	void AppendElement(const Element& element);
	void SetElement(const std::vector<Render::Element>& elements);

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

#endif /* SOURCE_CORE_RENDER_RENDERLAYOUT_H_ */
