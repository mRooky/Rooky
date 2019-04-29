/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include <GHIImageLayout.h>
#include "GHIBuffer.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

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

void Vertex::Create(GHI::VertexElement* element, uint32_t count)
{
	GHI::UsageType usage;
	usage.source = TRUE;
	usage.destination = TRUE;
	usage.type = GHI::ResourceType::RESOURCE_TYPE_BUFFER;
	Create(element, count, usage);
}

void Vertex::Create(GHI::VertexElement* element, uint32_t count, GHI::UsageType usage)
{
	mCount = count;
	mElement = *element;
	CreateRenderBuffer(usage);
	std::cout << "Create Vertex Count : " << mCount << std::endl;
}

void Vertex::CreateRenderBuffer(GHI::UsageType usage)
{
	assert(mElement.IsValid());
	size_t size = mElement.GetStride() * mCount;
	assert(size > 0);
	usage.vertexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<GHI::Buffer*>(mResource)->Create(size, usage);
}

} /* namespace Core */
