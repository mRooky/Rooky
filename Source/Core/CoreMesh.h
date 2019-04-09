/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "CoreMovable.h"
#include "CoreStream.h"
#include "RenderAABB.h"

#include <array>
#include <vector>

namespace Core
{
class Index;
class Vertex;
class SubMesh;
class MeshManager;
class Mesh : public Movable
{
	friend class MeshManager;
protected:
	explicit Mesh(MeshManager* manager);

public:
	virtual ~Mesh(void) override;

public:
	void SetIndex(Index* index, size_t offset);
	void SetVertex(Vertex* vertex, size_t offset);

public:
	SubMesh* CreateSubMesh(void);

public:
	inline Index* GetIndex(void) const { return mIndex; }
	inline size_t GetIndexOffset(void) const { return mIndexOffset; }
	inline Vertex* GetVertex(void) const { return mVertex; }
	inline size_t  GetVertexOffset(void) const { return mVertexOffset; }

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

protected:
	inline Stream* GetStream(void) { return &mStream; }
	inline Render::AABB* GetAABB(void) { return &mAABB; }

protected:
	Stream mStream;
	Render::AABB mAABB = {};

protected:
	Index* mIndex = nullptr;
	size_t mIndexOffset = 0;
	Vertex* mVertex = nullptr;
	size_t  mVertexOffset = 0;

protected:
	MeshManager* mManager = nullptr;
	std::vector<SubMesh*> mSubMeshes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
