/*
 * RenderDrawDirect.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_DRAWCALL_RENDERDRAWDIRECT_H_
#define SOURCE_CORE_RENDER_DRAWCALL_RENDERDRAWDIRECT_H_

#include "RenderDrawCall.h"

namespace Render
{

class DrawDirect : public DrawCall
{
protected:
	DrawDirect(void);
	virtual ~DrawDirect(void) override;

public:
	inline uint32_t GetInstanceCount(void) const { return mInstanceCount; }
	inline uint32_t GetFirstInstance(void) const { return mFirstInstance; }

public:
	inline void SetInstanceCount(uint32_t count) { mInstanceCount = count; }
	inline void SetFirstInstance(uint32_t first) { mFirstInstance = first; }

protected:
	uint32_t mInstanceCount = 1;
	uint32_t mFirstInstance = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_DRAWCALL_RENDERDRAWDIRECT_H_ */
