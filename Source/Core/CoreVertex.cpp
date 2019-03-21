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
	mDeclaration = nullptr;
}

void Vertex::Create(Render::Declaration* decl, uint32_t count, Render::AllocateType allocate)
{
	mCount = count;
	mDeclaration = decl;
	size_t size = mDeclaration->GetStride() * count;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.VertexBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
