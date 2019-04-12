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
}

void Vertex::Create(Render::VertexLayout* layout, uint32_t count)
{
	Render::UsageType usage;
	usage.source = TRUE;
	usage.destination = TRUE;
	usage.type = Render::ResourceType::RESOURCE_TYPE_BUFFER;
	Create(layout, count, usage);
}

void Vertex::Create(Render::VertexLayout* layout, uint32_t count, Render::UsageType usage)
{
	mCount = count;
	mLayout = layout;
	CreateRenderBuffer(usage);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

void Vertex::CreateRenderBuffer(Render::UsageType usage)
{
	assert(mLayout->IsValid());
	size_t size = mLayout->GetStride() * mCount;
	assert(size > 0);
	usage.vertexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<Render::Buffer*>(mResource)->Create(size, usage);
}

} /* namespace Core */
