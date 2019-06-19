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
	GHI::UsageType usage;
	usage.read = TRUE;
	usage.write = TRUE;
	usage.type = GHI::ResourceType::BUFFER;
	Create(layout, count, usage);
}

void Vertex::Create(GHI::VertexLayout* layout, uint32_t count, GHI::UsageType usage)
{
	mCount = count;
	mLayout = *layout;
	assert(mLayout.IsValid());
	size_t size = mLayout.GetStride() * mCount;
	assert(size > 0);
	usage.vertexBuffer = TRUE;
	mHostMemory.Allocate(size);
	CreateRenderBuffer(size, usage);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

} /* namespace Core */
