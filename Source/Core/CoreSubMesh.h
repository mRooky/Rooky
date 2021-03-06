/*
 * CoreSubMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESUBMESH_H_
#define SOURCE_CORE_CORESUBMESH_H_

#include "CoreRenderable.h"
#include "GHI/GHIClasses.h"
#include <cstdint>

namespace Core
{
class Mesh;
class SubMesh : public Renderable
{
	friend class Mesh;
private:
	explicit SubMesh(Mesh* parent);

public:
	virtual ~SubMesh(void);

public:
	virtual bool IsVisible(const Math::Frustum& frustum) override;

public:
	inline void SetFirstIndex(uint32_t first) { mFirstIndex = first; }
	inline void SetIndexCount(uint32_t count) { mIndexCount = count; }
	inline void SetFirstVertex(uint32_t first) { mFirstVertex = first; }
	inline void SetVertexCount(uint32_t count) { mVertexCount = count; }

public:
	inline uint32_t GetFirstIndex(void) const { return mFirstIndex; }
	inline uint32_t GetIndexCount(void) const { return mIndexCount; }
	inline uint32_t GetFirstVertex(void) const { return mFirstVertex; }
	inline uint32_t GetVertexCount(void) const { return mVertexCount; }

public:
	inline Mesh* GetParent(void) const { return mParent; }
	inline void SetParent(Mesh* parent) { mParent = parent; }

protected:
	Mesh* mParent = nullptr;

protected:
	uint32_t mFirstIndex = 0;
	uint32_t mIndexCount = 0;
	uint32_t mFirstVertex = 0;
	uint32_t mVertexCount = 0; //TODO for what ?
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESUBMESH_H_ */
