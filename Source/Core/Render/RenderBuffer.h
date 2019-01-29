/*
 * RenderBuffer.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERBUFFER_H_

#include "RenderResource.h"

namespace Render
{

class Buffer : public Resource
{
public:
	explicit Buffer(Context* context);
	virtual ~Buffer(void) override;

public:
	virtual void Initialize(size_t size, uint32_t usage) = 0;

public:
	inline uint32_t GetStride(void) const { return mStride; }

protected:
	uint32_t mStride = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
