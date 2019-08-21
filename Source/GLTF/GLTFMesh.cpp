/*
 * =====================================================================================
 *
 *       Filename:  GLTFMesh.cpp
 *
 * =====================================================================================
 */
#include "GLTFMesh.h"
#include "GLTFSubMesh.h"

namespace GLTF
{

Mesh::Mesh(void)
{

}

Mesh::~Mesh(void)
{
	for (auto sub : mSubMeshes)
	{
		delete sub;
	}
	mSubMeshes.clear();
}

SubMesh* Mesh::CreateSubMesh(void)
{
	auto sub = new SubMesh(this);
	mSubMeshes.push_back(sub);
	return sub;
}

}

