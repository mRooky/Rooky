/*
 * CoreBufferManager.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"

#include <cassert>

namespace Core
{

BufferManager::BufferManager(System* system):
		mSystem(system)
{
	assert(mSystem != nullptr);
}

BufferManager::~BufferManager(void)
{
	for (auto index : mIndexes)
	{
		delete index;
	}
	mIndexes.clear();
	for (auto vertex : mVertexes)
	{
		delete vertex;
	}
	mVertexes.clear();
	for (auto uniform : mUniforms)
	{
		delete uniform;
	}
	mUniforms.clear();
	mSystem = nullptr;
}

Index* BufferManager::CreateIndex(void)
{
	Index* index = new Index(this);
	mIndexes.push_back(index);
	return index;
}

Vertex* BufferManager::CreateVertex(void)
{
	Vertex* vertex = new Vertex(this);
	mVertexes.push_back(vertex);
	return vertex;
}

Uniform* BufferManager::CreateUniform(void)
{
	Uniform* uniform = new Uniform(this);
	mUniforms.push_back(uniform);
	return uniform;
}

} /* namespace Core */
