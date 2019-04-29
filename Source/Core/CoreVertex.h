/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "GHIClasses.h"
#include "GHIFormat.h"
#include "GHIUsageType.h"
#include "GHIVertexElement.h"
#include "CoreBuffer.h"
#include <cstdint>
#include <vector>

namespace Core
{
class BufferManager;
class Vertex : public Buffer
{
	friend class BufferManager;
private:
	explicit Vertex(BufferManager* creator);

public:
	virtual ~Vertex(void) override;

public:
	void Create(GHI::VertexElement* element, uint32_t count);
	void Create(GHI::VertexElement* element, uint32_t count, GHI::UsageType usage);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline const GHI::VertexElement& GetElement(void) const { return mElement; }

private:
	void CreateRenderBuffer(GHI::UsageType usage);

protected:
	BufferManager* mCreator = nullptr;

protected:
	uint32_t mCount = 0;
	GHI::VertexElement mElement = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
