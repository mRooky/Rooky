/*
 * RenderMemory.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMEMORY_H_
#define SOURCE_CORE_RENDER_RENDERMEMORY_H_

#include "RenderObject.h"
#include <cstddef>
#include <cstdint>

namespace Render
{

class Memory : public Object
{
protected:
	explicit Memory(Context* context);
	virtual ~Memory(void) override;

public:
	virtual void Initialize(size_t size, uint32_t index, uint32_t property) = 0;

public:
	virtual void* Mapped(size_t offset, size_t range) = 0;
	virtual void UnMap(size_t offset, size_t range) = 0;

public:
	inline size_t GetSize(void) const { return mSize; }
	inline uint32_t GetProperty(void) const { return mProperty; }

protected:
	size_t mSize = 0;
	uint32_t mProperty = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERMEMORY_H_ */
