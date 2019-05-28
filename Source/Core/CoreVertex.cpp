/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"
#include "GHI/GHIImageLayout.h"
#include "GHI/GHIBuffer.h"
#include "GHI/GHIDevice.h"
#include "GHI/GHIFactory.h"

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
}

void Vertex::Create(GHI::VertexLayout* layout, uint32_t count)
{
	GHI::UsageType usage;
	usage.source = TRUE;
	usage.destination = TRUE;
	usage.type = GHI::ResourceType::BUFFER;
	Create(layout, count, usage);
}

void Vertex::Create(GHI::VertexLayout* layout, uint32_t count, GHI::UsageType usage)
{
	mCount = count;
	mLayout = *layout;
	CreateRenderBuffer(usage);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

void Vertex::CreateRenderBuffer(GHI::UsageType usage)
{
	assert(mLayout.IsValid());
	size_t size = mLayout.GetStride() * mCount;
	assert(size > 0);
	usage.vertexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<GHI::Buffer*>(mResource)->Create(size, usage);
}

} /* namespace Core */
