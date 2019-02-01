/*
 * VKBufferManager.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#include "VKBufferManager.h"
#include "VKContext.h"
#include "VKIndex.h"
#include "VKVertex.h"
#include "VKUniform.h"

namespace VK
{

BufferManager::BufferManager(Context* context):
		Render::BufferManager(context)
{
}

BufferManager::~BufferManager(void)
{
}

Render::Index* BufferManager::CreateIndexBuffer(void)
{
	Index* index = new Index(this);
	mIndexes.push_back(index);
	return index;
}

Render::Vertex* BufferManager::CreateVertexBuffer(void)
{
	Vertex* vertex = new Vertex(this);
	mVertexes.push_back(vertex);
	return vertex;
}

Render::Uniform* BufferManager::CreateUniformBuffer(void)
{
	Uniform* uniform = new Uniform(this);
	mUniforms.push_back(uniform);
	return uniform;
}

} /* namespace VK */
