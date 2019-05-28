/*
 * CoreIndex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINDEX_H_
#define SOURCE_CORE_COREINDEX_H_

#include "CoreBuffer.h"
#include "GHI/GHIClasses.h"
#include "GHI/GHIEnum.h"
#include "GHI/GHIUsageType.h"
#include "GHI/Draw/GHIDrawIndexed.h"
#include <cstddef>

namespace Core
{
class BufferManager;
class Index : public Buffer
{
	friend class BufferManager;
private:
	explicit Index(BufferManager* creator);

public:
	virtual ~Index(void) override;

public:
	void Create(GHI::IndexType type, uint32_t count);
	void Create(GHI::IndexType type, uint32_t count, GHI::UsageType usage);

public:
	size_t GetSizeInByte(void);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline GHI::IndexType GetType(void) const { return mType; }
	inline GHI::DrawIndexed* GetDraw(void) { return &mDrawIndexed; }

private:
	void CreateRenderBuffer(GHI::UsageType usage);

public:
	BufferManager* mCreator = nullptr;

protected:
	uint32_t mCount = 0;
	GHI::DrawIndexed mDrawIndexed = {};
	GHI::IndexType mType = GHI::IndexType::INDEX_TYPE_UNKNOWN;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINDEX_H_ */
