/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include "MathAABB.h"
#include "CoreMovable.h"
#include <array>
#include <vector>

namespace Core
{
class Stream;
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
	bool Compile(void);

public:
	size_t GetIndexCount(void);
	size_t GetVertexCount(void);

public:
	SubMesh* CreateSubMesh(void);

public:
	inline size_t GetSubMeshCount(void) const { return mSubMeshes.size(); }
	inline SubMesh* GetSubMesh(size_t index) const { return mSubMeshes.at(index); }

public:
	inline Stream* GetStream(void) { return mStream; }
	inline Math::AABB* GetAABB(void) { return &mAABB; }

protected:
	Math::AABB mAABB = {};
	Stream* mStream = nullptr;

protected:
	MeshManager* mManager = nullptr;
	std::vector<SubMesh*> mSubMeshes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
