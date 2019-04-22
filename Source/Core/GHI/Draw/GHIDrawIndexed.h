/*
 * RenderDrawIndexed.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXED_H_
#define SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXED_H_

#include "GHIDrawDirect.h"

namespace GHI
{

class DrawIndexed: public DrawDirect
{
public:
	DrawIndexed(void);
	virtual ~DrawIndexed(void) override;

public:
	inline uint32_t GetIndexCount(void) const { return mIndexCount; }
	inline uint32_t GetFirstIndex(void) const { return mFirstIndex; }
	inline uint32_t GetVertexOffset(void) const { return mVertexOffset; }

public:
	inline void SetIndexCount(uint32_t count) { mIndexCount = count; }
	inline void SetFirstIndex(uint32_t first) { mFirstIndex = first; }
	inline void SetVertexOffset(uint32_t offset) { mVertexOffset = offset; }

protected:
	uint32_t mIndexCount = 0;
	uint32_t mFirstIndex = 0;
	uint32_t mVertexOffset = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXED_H_ */
