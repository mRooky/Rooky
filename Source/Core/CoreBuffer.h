/*
 * CoreBuffer.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFER_H_
#define SOURCE_CORE_COREBUFFER_H_

#include "CoreResource.h"
#include "GHI/GHIUsageType.h"

namespace Core
{

class BufferManager;
class Buffer: public Resource
{
public:
	Buffer(BufferManager* creator);
	virtual ~Buffer(void) override;

public:
	void Read(void* dst, size_t offset, size_t size);
	void Write(const void* src, size_t offset, size_t size);

public:
	inline BufferManager* GetManager(void) const { return mCreator; }

protected:
	void CreateRenderBuffer(size_t size, GHI::UsageType usage);

protected:
	BufferManager* mCreator = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFER_H_ */
