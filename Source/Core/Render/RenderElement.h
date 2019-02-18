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

class Element : public Object
{
protected:
	explicit Element(Context* context);

public:
	virtual ~Element(void) override;

public:
	void AppendSemantic(Format semantic);
	void RemoveSemantic(size_t index);

public:
	inline size_t GetStride(void) const { return mStride; }
	inline size_t GetCount(void) const { return mSemantics.size(); }
	inline Format GetSemantic(uint32_t index) const { return mSemantics.at(index); }

protected:
	size_t mStride = 0;
	std::vector<Format> mSemantics;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERELEMENT_H_ */
