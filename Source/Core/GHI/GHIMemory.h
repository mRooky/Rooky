/*
 * RenderMemory.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERMEMORY_H_
#define SOURCE_CORE_GHI_RENDERMEMORY_H_

#include "GHIResource.h"
#include "GHIResourceUsage.h"
#include <cstddef>

namespace GHI
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
	inline size_t GetAlignSize(void) const { return mAlignSize; }

public:
	inline const ResourceUsage& GetUsage(void) const { return mUsage; }
	inline bool operator==(const ResourceUsage& usage) const { return mUsage == usage; }

protected:
	size_t mAlignSize = 0;
	ResourceUsage mUsage = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERMEMORY_H_ */
