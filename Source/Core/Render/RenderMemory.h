/*
 * RenderMemory.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMEMORY_H_
#define SOURCE_CORE_RENDER_RENDERMEMORY_H_

#include "RenderObject.h"
#include "RenderUsage.h"
#include <cstddef>

namespace Render
{
class Buffer;
class Memory: public Object
{
public:
	Memory(Context* context);
	virtual ~Memory(void) override;

public:
	virtual void* Map(size_t offset, size_t size) = 0;
	virtual void Unmap(size_t offset, size_t size) = 0;

public:
	virtual void CopyFrom(const Buffer* buffer) = 0;

public:
	inline size_t GetHeapSize(void) const { return mHeapSize; }

protected:
	size_t mHeapSize = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERMEMORY_H_ */
