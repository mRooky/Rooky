/*
 * CoreIndex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINDEX_H_
#define SOURCE_CORE_COREINDEX_H_

#include "CoreBuffer.h"
#include "GHI/GHIIndexType.h"
#include "GHI/Draw/GHIDrawIndexed.h"
#include <cstddef>

namespace Core
{

class Index : public Buffer
{
	friend class BufferManager;
private:
	explicit Index(BufferManager* creator);

public:
	virtual ~Index(void) override;

public:
	void Create(GHI::IndexType type, uint32_t count);
	void Create(GHI::IndexType type, uint32_t count, GHI::MemoryUsage& usage);

public:
	size_t GetSizeInByte(void);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline GHI::IndexType GetType(void) const { return mType; }
	inline GHI::DrawIndexed* GetDraw(void) { return &mDrawIndexed; }

protected:
	uint32_t mCount = 0;
	GHI::DrawIndexed mDrawIndexed = {};
	GHI::IndexType mType = GHI::IndexType::UNKNOWN;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINDEX_H_ */
