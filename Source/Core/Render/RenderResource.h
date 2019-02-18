/*
 * RenderResource.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCE_H_

#include "RenderObject.h"
#include "RenderTypes.h"
#include <cstddef>
#include <cstdint>

namespace Render
{
class Buffer;
class Resource : public Object
{
protected:
	explicit Resource(Context* context);
	virtual ~Resource(void) override;

public:
	virtual void* Map(size_t offset, size_t size) = 0;
	virtual void Unmap(size_t offset, size_t size) = 0;

public:
	virtual void CopyFrom(const Buffer* buffer) = 0;

public:
	inline size_t GetSize(void) const { return mSize; }
	inline uint32_t GetUsage(void) const { return mUsage; }
	inline HeapAccess GetAccess(void) const { return mAccess; }

protected:
	size_t mSize = 0;
	uint32_t mUsage = 0;
	HeapAccess mAccess = HeapAccess::HEAP_ACCESS_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCE_H_ */
