/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderVertexLayout.h"
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
	mLayout = nullptr;
}

void Vertex::Create(Render::VertexLayout* layout, uint32_t count, Render::AllocateType allocate)
{
	mCount = count;
	mLayout = layout;
	CreateBuffer(allocate);
}

void Vertex::CreateBuffer(Render::AllocateType allocate)
{
	size_t size = mLayout->GetSizeInByte() * mCount;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.VertexBuffer = 1;
	Buffer::Create(size, buffer_usage);
}

} /* namespace Core */
