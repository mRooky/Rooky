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
	void Create(const std::vector<Render::Element>& elements);

public:
	void AppendElement(const Element& element);

public:
	inline const std::vector<Element>& GetElements(void) const { return mElements; }

public:
	inline bool IsValid(void) const { return mValid; }
	inline size_t GetSizeInByte(void) const { return mSizeInByte; }
	inline size_t GetCount(void) const { return mElements.size(); }
	inline const Element& GetElement(uint32_t index) const { return mElements.at(index); }

protected:
	bool mValid = false;
	size_t mSizeInByte = 0;
	std::vector<Element> mElements;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERVERTEXLAYOUT_H_ */
