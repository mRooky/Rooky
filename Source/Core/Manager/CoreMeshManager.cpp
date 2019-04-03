/*
 * CoreMeshManager.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#include "CoreMeshManager.h"
#include "CoreBufferManager.h"
#include "CoreMesh.h"

#include "UtilityRelease.h"

namespace Core
{

MeshManager::MeshManager(System* system):
		Object(system)
{
	mBufferManager = new BufferManager(system);
}

MeshManager::~MeshManager(void)
{
	delete mBufferManager;
	mBufferManager = nullptr;
	Utility::Release(mMeshes);
}

Mesh* MeshManager::GetMesh(const char* name)
{
	const std::string mesh_name(name);
	for (auto mesh : mMeshes)
	{
		auto curr_name = mesh->GetName();
		if (mesh_name == curr_name)
		{
			return mesh;
		}
	}
	return nullptr;
}

Mesh* MeshManager::CreateMesh(const char* name)
{
	Mesh* mesh = new Mesh(this);
	mesh->SetName(name);
	mMeshes.push_back(mesh);
	return mesh;
}

} /* namespace Core */
