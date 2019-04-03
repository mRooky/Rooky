/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderVertexLayout.h"
#include "RenderBuffer.h"
#include "RenderDevice.h"
#include "RenderFactory.h"

#include <cassert>
#include <iostream>

namespace Core
{

Vertex::Vertex(BufferManager* creator):
		mCreator(creator)
{
}

Vertex::~Vertex(void)
{
	mCount = 0;
	mLayout = nullptr;
	delete mBuffer;
	mBuffer = nullptr;
}

void Vertex::Create(Render::VertexLayout* layout, uint32_t count, Render::AllocateType allocate)
{
	mCount = count;
	mLayout = layout;
	CreateRenderBuffer(allocate);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

void Vertex::CreateRenderBuffer(Render::AllocateType allocate)
{
	assert(mLayout->IsValid());
	size_t size = mLayout->GetSizeInByte() * mCount;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.VertexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::Factory* factory = device->GetFactory();
	mBuffer = factory->CreateBuffer();
	mBuffer->Create(size, buffer_usage);
}

} /* namespace Core */
