/*
 * RenderDrawArray.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWARRAY_H_
#define SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWARRAY_H_

#include "GHIDrawDirect.h"

namespace GHI
{

class DrawArray: public DrawDirect
{
public:
	DrawArray(void);
	virtual ~DrawArray(void) override;

public:
	inline uint32_t GetVertexCount(void) const
	{
		return mVertexCount;
	}

	inline uint32_t GetFirstVertex(void) const
	{
		return mFirstVertex;
	}

public:
	inline void SetVertexCount(uint32_t count)
	{
		mVertexCount = count;
	}

	inline void SetFirstVertex(uint32_t first)
	{
		mFirstVertex = first;
	}

protected:
	uint32_t mVertexCount = 0;
	uint32_t mFirstVertex = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWARRAY_H_ */
