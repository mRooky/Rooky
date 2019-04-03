/*
 * CoreIndex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINDEX_H_
#define SOURCE_CORE_COREINDEX_H_

#include "RenderDrawIndexed.h"
#include "RenderEnum.h"
#include "RenderUsage.h"
#include "RenderClasses.h"

#include <cstddef>

namespace Core
{
class BufferManager;
class Index
{
	friend class BufferManager;
private:
	explicit Index(BufferManager* creator);

public:
	virtual ~Index(void);

public:
	void Create(Render::IndexType type, uint32_t count, Render::AllocateType allocate);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline Render::Buffer* GetBuffer(void) { return mBuffer; }
	inline Render::IndexType GetType(void) const { return mType; }
	inline Render::DrawIndexed* GetDraw(void) { return &mDrawIndexed; }

private:
	void CreateRenderBuffer(Render::AllocateType allocate);

public:
	BufferManager* mCreator = nullptr;

protected:
	uint32_t mCount = 0;
	Render::Buffer* mBuffer = nullptr;
	Render::DrawIndexed mDrawIndexed = {};
	Render::IndexType mType = Render::IndexType::INDEX_TYPE_UNKNOWN;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINDEX_H_ */
