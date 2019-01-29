/*
 * CoreMesh.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "CoreMesh.h"
#include "CoreSubMesh.h"

namespace Core
{

Mesh::Mesh(void)
{
}

Mesh::~Mesh(void)
{
}

SubMesh* Mesh::CreateSubMesh(void)
{
	SubMesh* sub = new SubMesh(this);
	m_subMeshes.push_back(sub);
	return sub;
}

} /* namespace Core */
