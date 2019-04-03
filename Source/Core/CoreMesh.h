/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "CoreBase.h"
#include "CoreDataType.h"
#include "RenderAABB.h"

#include <array>
#include <vector>
#include <string>

namespace Core
{
class Index;
class Vertex;
class Material;
class SubMesh;
class MeshManager;
class Mesh : public Base
{
	friend class MeshManager;
protected:
	explicit Mesh(MeshManager* manager);

public:
	virtual ~Mesh(void) override;

public:
	SubMesh* CreateSubMesh(void);

public:
	void* Allocate(StreamType type, size_t size, bool discard = true);

public:
	inline Index* GetIndex(void) const { return mIndex; };
	inline void SetIndex(Index* index) { mIndex = index; };

public:
	inline Vertex* GetVertex(void) const { return mVertex; }
	inline void SetVertex(Vertex* vertex) { mVertex = vertex; }

public:
	inline Material* GetMaterial(void) const { return mMaterial; }
	inline void SetMaterial(Material* material) { mMaterial = material; }

public:
	inline void* GetStream(StreamType type)
	{
		uint32_t index = static_cast<uint32_t>(type);
		return mSubMeshes.at(index);
	}

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

protected:
	void FreeAllStream(void);
	void FreeStream(StreamType type);

protected:
	Render::AABB mAABB = {};
	MeshManager* mManager = nullptr;

protected:
	Index* mIndex = nullptr;
	size_t mIndexOffset = 0;

protected:
	Vertex* mVertex = nullptr;
	size_t  mVertexOffset = 0;

protected:
	Material* mMaterial = nullptr;
	std::vector<SubMesh*> mSubMeshes;

protected:
	std::array<uint8_t*, STREAM_TYPE_COUNT> mStreams;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
