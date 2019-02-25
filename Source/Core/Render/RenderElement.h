/*
 * RenderDeclaration.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERELEMENT_H_
#define SOURCE_CORE_RENDER_RENDERELEMENT_H_

#include "RenderObject.h"
#include "RenderFormat.h"

#include <vector>

namespace Render
{

class Element
{
public:
	Element(uint32_t binding, Format format);
	~Element(void);

public:
	void Create(uint32_t binding, Format format);

public:
	inline Format GetFormat(void) const { return mFormat; }
	inline uint32_t GetBinding(void) const { return mBinding; }

protected:
	uint32_t mBinding = 0;
	Format mFormat = Format::FORMAT_UNDEFINED;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERELEMENT_H_ */
