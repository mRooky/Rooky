/*
 * CoreIndex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINDEX_H_
#define SOURCE_CORE_COREINDEX_H_

#include <RenderDraw/RenderDrawIndexed.h>
#include "CoreBuffer.h"
#include "RenderEnum.h"
#include "RenderUsage.h"


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
	void Create(Render::IndexType type, uint32_t count, Render::AllocateType allocate);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline Render::IndexType GetType(void) const { return mType; }
	inline Render::DrawIndexed* GetDraw(void) { return &mDrawIndexed; }

private:
	void CreateBuffer(Render::AllocateType allocate);

protected:
	uint32_t mCount = 0;
	Render::DrawIndexed mDrawIndexed = {};
	Render::IndexType mType = Render::IndexType::INDEX_TYPE_UNKNOWN;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINDEX_H_ */
