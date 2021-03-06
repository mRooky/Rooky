/*
 * RenderDrawCall.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_DRAW_RENDERDRAWCALL_H_
#define SOURCE_CORE_RENDER_DRAW_RENDERDRAWCALL_H_

#include <cstdint>

namespace GHI
{

enum class DrawType : uint32_t
{
	DRAW_TYPE_ARRAY,
	DRAW_TYPE_INDEXED,
	DRAW_TYPE_INDEXED_INDIRECT,
	DRAW_TYPE_INDIRECT,
	DRAW_TYPE_UNKNOWN = ~0U
};

class Draw
{
protected:
	Draw(void);
	virtual ~Draw(void);

public:
	inline DrawType GetType(void) const { return mType; }

protected:
	DrawType mType = DrawType::DRAW_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_DRAW_RENDERDRAWCALL_H_ */
