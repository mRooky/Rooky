/*
 * RenderMemory.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMEMORY_H_
#define SOURCE_CORE_RENDER_RENDERMEMORY_H_

#include "RenderResource.h"
#include <cstddef>

namespace Render
{
class Buffer;
class Memory: public Resource
{
protected:
	Memory(Device* device);
	virtual ~Memory(void) override;

public:
	virtual void* Map(size_t offset, size_t size) = 0;
	virtual void Unmap(size_t offset, size_t size) = 0;

public:
	virtual void CopyFrom(const Resource* other) = 0;

public:
	inline size_t GetHeapSize(void) const { return mHeapSize; }

protected:
	size_t mHeapSize = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERMEMORY_H_ */
