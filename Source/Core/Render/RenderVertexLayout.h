/*
 * RenderVertexLayout.h
 *
 *  Created on: Mar 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVERTEXLAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERVERTEXLAYOUT_H_

#include "RenderElement.h"
#include <vector>

namespace Render
{

class VertexLayout
{
public:
	VertexLayout(void);
	virtual ~VertexLayout(void);

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

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERVERTEXLAYOUT_H_ */
