/*
 * RenderMemory.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMEMORY_H_
#define SOURCE_CORE_RENDER_RENDERMEMORY_H_

#include "RenderResource.h"

namespace Render
{
class Buffer;
class Memory: public Resource
{
public:
	Memory(Context* context);
	virtual ~Memory(void) override;

public:
	virtual void Allocate(HeapAccess access) = 0;

public:
	virtual void* Map(size_t offset, size_t size) = 0;
	virtual void Unmap(size_t offset, size_t size) = 0;

public:
	virtual void CopyFrom(const Buffer* buffer) = 0;

public:
	inline size_t GetSize(void) const { return mSize; }
	inline HeapAccess GetAccess(void) const { return mAccess; }

protected:
	size_t mSize = 0;
	HeapAccess mAccess = HeapAccess::HEAP_ACCESS_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERMEMORY_H_ */
