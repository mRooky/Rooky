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
#include "RenderDeclaration.h"


#include <cstdint>
#include <vector>

namespace Core
{
class Vertex : public Buffer
{
	friend class BufferManager;
private:
	explicit Vertex(BufferManager* creator);
	virtual ~Vertex(void) override;

public:
	void Create(std::vector<Render::Element> elements, uint32_t count, Render::HeapAccess access);

public:
	inline uint32_t GetCount(void) const { return mCount; }
	inline Render::Declaration* GetDeclaration(void) const { return mDeclaration; }

protected:
	uint32_t mCount = 0;
	Render::Declaration* mDeclaration = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
