/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "CoreMovable.h"
#include "CoreDataType.h"
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
	void* Allocate(StreamType type, size_t size, bool discard);

public:
	inline void* GetStream(StreamType type)
	{
		uint32_t index = static_cast<uint32_t>(type);
		return mSubMeshes.at(index);
	}

public:
	inline Index* GetIndex(void) const { return mIndex; }
	inline size_t GetIndexOffset(void) const { return mIndexOffset; }
	inline Vertex* GetVertex(void) const { return mVertex; }
	inline size_t  GetVertexOffset(void) const { return mVertexOffset; }

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

protected:
	void FreeAllStream(void);
	void FreeStream(StreamType type);

protected:
	inline Render::AABB* GetAABB(void) { return &mAABB; }

protected:
	Render::AABB mAABB = {};

protected:
	Index* mIndex = nullptr;
	size_t mIndexOffset = 0;
	Vertex* mVertex = nullptr;
	size_t  mVertexOffset = 0;

protected:
	MeshManager* mManager = nullptr;
	std::vector<SubMesh*> mSubMeshes;
	std::array<uint8_t*, STREAM_TYPE_COUNT> mStreams;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
