/*
 * CoreMesh.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMESH_H_
#define SOURCE_CORE_COREMESH_H_

#include <vector>

namespace Core
{
class SubMesh;
class Mesh
{
public:
	Mesh(void);
	virtual ~Mesh(void);

public:
	SubMesh* CreateSubMesh(void);

public:
	inline SubMesh* GetSubMesh(size_t index) const { return m_subMeshes.at(index); }

private:
	std::vector<SubMesh*> m_subMeshes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMESH_H_ */
