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
public:
	explicit Element(Context* context);
	virtual ~Element(void) override;

public:
	void Create(const std::vector<Format>& formats);

public:
	inline size_t GetStride(void) const { return mStride; }
	inline size_t GetElementCount(void) const { return mFormats.size(); }
	inline Format GetElementFormat(uint32_t index) const { return mFormats.at(index); }

protected:
	size_t mStride = 0;
	std::vector<Format> mFormats;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERELEMENT_H_ */
