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
	mStreams.fill(nullptr);
}

Mesh::~Mesh(void)
{
	FreeAllStream();
	Utility::Release(mSubMeshes);
	mManager = nullptr;
}

SubMesh* Mesh::CreateSubMesh(void)
{
	SubMesh* sub = new SubMesh(this);
	mSubMeshes.push_back(sub);
	return sub;
}

void* Mesh::Allocate(StreamType type, size_t size, bool discard)
{
	if (discard)
	{
		FreeStream(type);
	}
	uint8_t* buffer = new uint8_t[size];
	uint32_t index = static_cast<uint32_t>(type);
	mStreams.at(index) = buffer;
	return buffer;
}

void Mesh::FreeAllStream(void)
{
	for (uint32_t index = 0; index < STREAM_TYPE_COUNT; ++index)
	{
		auto type = static_cast<StreamType>(index);
		FreeStream(type);
	}
}

void Mesh::FreeStream(StreamType type)
{
	uint32_t index = static_cast<uint32_t>(type);
	uint8_t* buffer = mStreams.at(index);
	delete[] buffer;
	mStreams.at(index) = nullptr;
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
