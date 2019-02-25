/*
 * RenderDeclaration.h
 *
 *  Created on: Feb 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERDECLARATION_H_
#define SOURCE_CORE_RENDER_RENDERDECLARATION_H_

#include "RenderElement.h"
#include <vector>

namespace Render
{
class Declaration
{
public:
	Declaration(void);
	virtual ~Declaration(void);

public:
	void Create(const std::vector<Element>& elements);

public:
	inline size_t GetStride(void) const { return mStride; }
	inline size_t GetCount(void) const { return mElements.size(); }
	inline const Element& GetElement(uint32_t index) const { return mElements.at(index); }

protected:
	size_t mStride = 0;
	std::vector<Element> mElements;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERDECLARATION_H_ */
