/*
 * RenderVertex.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVERTEX_H_
#define SOURCE_CORE_RENDER_RENDERVERTEX_H_

#include "RenderBuffer.h"
#include <vector>
#include <cstdint>

namespace Render
{
class Declaration;
class Vertex: public Buffer
{
protected:
	explicit Vertex(BufferManager* manager);
	virtual ~Vertex(void) override;

public:
	virtual void Initialize(Declaration* decl, size_t count) = 0;

public:
	inline size_t GetCount(void) const { return mCount; }
	inline uint32_t GetStride(void) const { return mStride; }
	inline Declaration* GetDeclaration(void) const { return mDeclaration; }

protected:
	size_t mCount = 0;
	uint32_t mStride = 0;
	Declaration* mDeclaration = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERVERTEX_H_ */
