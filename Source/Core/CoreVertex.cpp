/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderDeclaration.h"
#include "RenderContext.h"
#include "RenderBuffer.h"

#include <cassert>

namespace Core
{

Vertex::Vertex(BufferManager* creator):
		Buffer(creator)
{
}

Vertex::~Vertex(void)
{
	mCount = 0;
	delete mDeclaration;
	mDeclaration = nullptr;
}

void Vertex::Create(Render::Declaration* decl, uint32_t count, Render::ResourceHeap heap)
{
	mCount = count;
	mDeclaration = decl;
	size_t size = mDeclaration->GetStride() * count;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.heap = heap;
	buffer_usage.binding.VertexBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
