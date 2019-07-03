/*
 * CoreBuffer.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFER_H_
#define SOURCE_CORE_COREBUFFER_H_

#include "CoreResource.h"
#include "CoreHostMemory.h"
#include "GHI/GHIResourceUsage.h"

namespace Core
{

class BufferManager;
class Buffer: public Resource
{
public:
	Buffer(BufferManager* creator);
	virtual ~Buffer(void) override;

public:
	void Upload(bool merge);

public:
	void Read(void* dst, size_t offset, size_t size);
	void Write(const void* src, size_t offset, size_t size);

public:
	inline HostMemory* GetHostMemory(void) { return &mHostMemory; }

public:
	inline BufferManager* GetManager(void) const { return mCreator; }

protected:
	void CreateRenderBuffer(size_t size, GHI::ResourceUsage& usage);

protected:
	HostMemory mHostMemory = {};
	BufferManager* mCreator = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
