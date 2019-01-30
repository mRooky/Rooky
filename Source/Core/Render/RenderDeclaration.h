/*
 * RenderDeclaration.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERDECLARATION_H_
#define SOURCE_CORE_RENDER_RENDERDECLARATION_H_

#include "RenderObject.h"
#include "RenderFormat.h"

#include <vector>

namespace Render
{

class Declaration : public Object
{
public:
	explicit Declaration(Context* context);
	virtual ~Declaration(void) override;

public:
	uint32_t GetStride(void) const;

public:
	inline size_t GetElementCount(void) const { return mFormats.size(); }
	inline Format GetElementFormat(uint32_t index) const { return mFormats.at(index); }

protected:
	std::vector<Format> mFormats;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERDECLARATION_H_ */
