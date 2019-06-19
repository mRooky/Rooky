/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "CoreBuffer.h"
#include "GHI/GHIVertexLayout.h"
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
	void Create(GHI::VertexLayout* layout, uint32_t count);
	void Create(GHI::VertexLayout* layout, uint32_t count, GHI::UsageType usage);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline const GHI::VertexLayout& GetLayout(void) const { return mLayout; }

protected:
	uint32_t mCount = 0;
	GHI::VertexLayout mLayout = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
