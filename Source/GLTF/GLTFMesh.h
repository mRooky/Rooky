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

namespace GLTF
{

class Material;
class Mesh
{
public:
	Mesh(void);
	~Mesh(void);

public:
	inline Core::Index* GetIndex(void)
	{
		return m_index;
	}

	inline Core::Vertex* GetVertex(void)
	{
		return m_vertex;
	}

public:
	inline Material* GetMaterial(void)
	{
		return m_material;
	}

	inline void SetMaterial(Material* material)
	{
		m_material = material;
	}

private:
	Math::AABB m_aabb = {};
	Core::Index* m_index = nullptr;
	Core::Vertex* m_vertex = nullptr;
	Material* m_material = nullptr;
};

}

#endif
