/*
 * CoreRenderable.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERABLE_H_
#define SOURCE_CORE_CORERENDERABLE_H_

#include "CoreBase.h"

namespace Core
{
class Index;
class Vertex;
class Material;
class Renderable : public Base
{
public:
	Renderable(void);
	virtual ~Renderable(void) override;

public:
	void SetIndex(Index* index, size_t offset);
	void SetVertex(Vertex* vertex, size_t offset);

public:
	inline Index* GetIndex(void) const { return mIndex; }
	inline size_t GetIndexOffset(void) const { return mIndexOffset; }

public:
	inline Vertex* GetVertex(void) const { return mVertex; }
	inline size_t  GetVertexOffset(void) const { return mVertexOffset; }

public:
	inline Material* GetMaterial(void) const { return mMaterial; }
	inline void SetMaterial(Material* material) { mMaterial = material; }

protected:
	Index* mIndex = nullptr;
	size_t mIndexOffset = 0;

protected:
	Vertex* mVertex = nullptr;
	size_t  mVertexOffset = 0;

protected:
	Material* mMaterial = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERABLE_H_ */
