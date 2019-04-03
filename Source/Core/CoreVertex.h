/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "RenderFormat.h"
#include "RenderClasses.h"
#include "RenderUsage.h"

#include <cstdint>
#include <vector>

namespace Core
{
class BufferManager;
class Vertex
{
	friend class BufferManager;
private:
	explicit Vertex(BufferManager* creator);

public:
	virtual ~Vertex(void);

public:
	void Create(Render::VertexLayout* layout, uint32_t count, Render::AllocateType allocate);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline Render::Buffer* GetBuffer(void) { return mBuffer; }
	inline Render::VertexLayout* GetLayout(void) const { return mLayout; }

private:
	void CreateRenderBuffer(Render::AllocateType allocate);

protected:
	BufferManager* mCreator = nullptr;

protected:
	uint32_t mCount = 0;
	Render::Buffer* mBuffer = nullptr;
	Render::VertexLayout* mLayout = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
