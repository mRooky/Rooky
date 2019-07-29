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

namespace GLTF
{

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);

public:
	inline Core::Index* GetIndex(void) { return m_index; }
	inline Core::Vertex* GetVertex(void) { return m_vertex; }

private:
	Core::Index* m_index = nullptr;
	Core::Vertex* m_vertex = nullptr;

};

}

#endif
