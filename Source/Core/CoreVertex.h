/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "CoreBuffer.h"
#include "RenderFormat.h"


#include <cstdint>
#include <vector>

namespace Core
{
class Vertex : public Buffer
{
	friend class BufferManager;
private:
	explicit Vertex(BufferManager* creator);

public:
	virtual ~Vertex(void) override;

public:
	void Create(Render::VertexLayout* layout, uint32_t count, Render::AllocateType allocate);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline Render::VertexLayout* GetLayout(void) const { return mLayout; }

private:
	void CreateBuffer(Render::AllocateType allocate);

protected:
	uint32_t mCount = 0;
	Render::VertexLayout* mLayout = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
