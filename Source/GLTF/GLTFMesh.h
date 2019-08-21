/*
 * =====================================================================================
 *
 *       Filename:  GLTFMesh.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_MESH_H
#define SOURCE_GLTF_MESH_H

#include "../Core/CoreIndex.h"
#include "../Core/CoreVertex.h"
#include "../Core/Math/MathAABB.h"
#include <vector>

namespace GLTF
{

class SubMesh;
class Mesh
{
public:
	Mesh(void);
	~Mesh(void);

public:
	SubMesh* CreateSubMesh(void);

public:
	inline size_t GetSubMeshCount(void) const
	{
		return mSubMeshes.size();
	}

	inline SubMesh* GetSubMesh(size_t index) const
	{
		return mSubMeshes.at(index);
	}

public:
	inline Core::Index* GetIndex(void)
	{
		return m_index;
	}

	inline Core::Vertex* GetVertex(void)
	{
		return m_vertex;
	}

private:
	Math::AABB m_aabb = {};
	Core::Index* m_index = nullptr;
	Core::Vertex* m_vertex = nullptr;

private:
	GHI::VertexLayout mLayout = {};
	std::vector<SubMesh*> mSubMeshes;
};

}

#endif
