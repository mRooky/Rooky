/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "CoreObject.h"
#include "CoreMeshBuffer.h"
#include "Math/MathAABB.h"
#include <array>
#include <vector>

namespace Core
{

class SubMesh;
class MeshManager;
class Mesh : public Object
{
	friend class MeshManager;
protected:
	explicit Mesh(MeshManager* manager);

public:
	virtual ~Mesh(void) override;

public:
	bool Create(void);

public:
	virtual void Render(Thread& thread) override;

public:
	size_t GetIndexCount(void);
	size_t GetVertexCount(void);

public:
	SubMesh* CreateSubMesh(void);

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

public:
	inline IndexBuffer* GetIndexBuffer(void) { return &mIndexBuffer; }
	inline VertexBuffer* GetVertexBuffer(void) { return &mVertexBuffer; }

public:
	inline Math::AABB* GetAABB(void) { return &mAABB; }
	inline const Math::AABB& GetAABB(void) const { return mAABB; }

protected:
	Math::AABB mAABB = {};
	IndexBuffer mIndexBuffer = {};
	VertexBuffer mVertexBuffer = {};

protected:
	MeshManager* mManager = nullptr;
	std::vector<SubMesh*> mSubMeshes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
