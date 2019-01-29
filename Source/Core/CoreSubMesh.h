/*
 * CoreSubMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESUBMESH_H_
#define SOURCE_CORE_CORESUBMESH_H_

#include "RenderClasses.h"

namespace Core
{
class Mesh;
class SubMesh
{
	friend class Mesh;
private:
	explicit SubMesh(Mesh* parent);
	virtual ~SubMesh(void);

public:
	inline Mesh* GetParent(void) const { return m_parent; }

public:
	inline Render::Index* GetIndex(void) const { return m_index; };
	inline Render::Vertex* GetVertex(void) const { return m_vertex; }

private:
	Mesh* m_parent = nullptr;

private:
	Render::Index* m_index = nullptr;
	Render::Vertex* m_vertex = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESUBMESH_H_ */
