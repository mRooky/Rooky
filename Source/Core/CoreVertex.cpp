/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreVertex.h"
#include <cassert>
#include <iostream>

namespace Core
{

Vertex::Vertex(BufferManager* creator):
		Buffer(creator)
{
}

Vertex::~Vertex(void)
{
	mCount = 0;
}

void Vertex::Create(GHI::VertexLayout* layout, uint32_t count)
{
	GHI::ResourceUsage usage;
	usage.memoryUsage.read = TRUE;
	usage.memoryUsage.write = TRUE;
	Create(layout, count, usage);
}

void Vertex::Create(GHI::VertexLayout* layout, uint32_t count, GHI::ResourceUsage& usage)
{
	mCount = count;
	mLayout = *layout;
	assert(mLayout.IsValid());
	size_t size = mLayout.GetStride() * mCount;
	assert(size > 0);
	usage.bufferUsage.vertexBuffer = TRUE;
	mHostMemory.Allocate(size);
	CreateRenderBuffer(size, usage);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

} /* namespace Core */
