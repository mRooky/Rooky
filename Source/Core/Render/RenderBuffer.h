/*
 * Buffer.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERBUFFER_H_

#include "RenderMemory.h"

namespace Render
{

class Buffer : public Memory
{
protected:
	explicit Buffer(Context* context);

public:
	virtual ~Buffer(void) override;

public:
	virtual void Create(size_t size, uint32_t usage) = 0;

protected:
	inline BufferUsage GetUsage(void) const { return mUsage; }

protected:
	BufferUsage mUsage = {};

};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
