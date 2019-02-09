/*
 * RenderResource.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCE_H_

#include "RenderObject.h"
#include <cstddef>
#include <cstdint>

namespace Render
{
class Memory;
class Resource : public Object
{
protected:
	explicit Resource(Context* context);
	virtual ~Resource(void) override;

public:
	virtual void Allocate(uint32_t properties) = 0;

public:
	inline size_t GetSize(void) const { return mSize; }
	inline uint32_t GetUsage(void) const { return mUsage; }
	inline Memory* GetMemory(void) const { return mMemory; }

protected:
	size_t mSize = 0;
	uint32_t mUsage = 0;

protected:
	Memory* mMemory = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCE_H_ */
