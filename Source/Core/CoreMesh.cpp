/*
 * CoreMesh.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "CoreMesh.h"
#include "CoreStream.h"
#include "CoreSubMesh.h"
#include "CoreMeshManager.h"
#include "CoreBufferManager.h"

#include "UtilityRelease.h"
#include <cassert>

namespace Core
{

Mesh::Mesh(MeshManager* manager):
		mManager(manager)
{
	mStream = new Stream(this);
}

Mesh::~Mesh(void)
{
	delete mStream;
	mStream = nullptr;
	Utility::Release(mSubMeshes);
	mManager = nullptr;
}

void Mesh::Render(Thread& thread)
{
	assert(false);
}

SubMesh* Mesh::CreateSubMesh(void)
{
	SubMesh* sub = new SubMesh(this);
	mSubMeshes.push_back(sub);
	return sub;
}

bool Mesh::Compile(void)
{
	BufferManager* buffer_manager = mManager->GetBufferManager();
	Index* index = buffer_manager->CreateIndex();
	mStream->GetIndexBuffer()->SetIndex(index);
	Vertex* vertex = buffer_manager->CreateVertex();
	mStream->GetVertexBuffer()->SetAttribute(vertex);
	return mStream->UploadData();
}

size_t Mesh::GetIndexCount(void)
{
	size_t count = 0;
	for (auto sub : mSubMeshes)
	{
		count += sub->GetIndexCount();
	}
	return count;
}

size_t Mesh::GetVertexCount(void)
{
	size_t count = 0;
	for (auto sub : mSubMeshes)
	{
		count += sub->GetVertexCount();
	}
	return count;
}

} /* namespace Core */
