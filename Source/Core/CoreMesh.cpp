/*
 * CoreMesh.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "CoreMesh.h"
#include "CoreSubMesh.h"

#include "UtilityRelease.h"

namespace Core
{

Mesh::Mesh(MeshManager* manager):
		mManager(manager)
{
}

Mesh::~Mesh(void)
{
	Utility::Release(mSubMeshes);
	mManager = nullptr;
}

SubMesh* Mesh::CreateSubMesh(void)
{
	SubMesh* sub = new SubMesh(this);
	mSubMeshes.push_back(sub);
	return sub;
}

void Mesh::SetIndex(Index* index, size_t offset)
{
	mIndex = index;
	mIndexOffset = offset;
}

void Mesh::SetVertex(Vertex* vertex, size_t offset)
{
	mVertex = vertex;
	mVertexOffset = offset;
}


} /* namespace Core */
