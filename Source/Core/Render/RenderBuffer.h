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
	explicit Buffer(Device* device);

public:
	virtual ~Buffer(void) override;

public:
	virtual void Create(size_t size, const ResourceUsage& usage) = 0;

public:
	virtual void Download(void* dst) = 0;
	virtual void Upload(const void* src) = 0;

public:
	inline size_t GetSize(void) const { return mSize; }

protected:
	size_t mSize = 0;

};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFER_H_ */
