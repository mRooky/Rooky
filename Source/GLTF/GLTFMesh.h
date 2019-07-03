/*
 * =====================================================================================
 *
 *       Filename:  GLTFMesh.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_MESH_H
#define SOURCE_GLTF_MESH_H

#include "../Core/CoreMeshBuffer.h"

namespace GLTF
{

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);

public:
	inline Core::IndexBuffer* GetIndex(void) { return &m_index; }
	inline Core::VertexBuffer* GetVertex(void) { return &m_vertex; }

private:
	Core::IndexBuffer m_index = {};
	Core::VertexBuffer m_vertex = {};

};

}

#endif
