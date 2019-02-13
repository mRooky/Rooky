/*
 * CoreVertex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreVertex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderElement.h"
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
	auto context = mCreator->GetSystem()->GetContext();
	context->DestroyObject(mBuffer);
	mBuffer = nullptr;
}

void Vertex::Create(Render::Element* element, uint32_t count)
{
	size_t size = element->GetStride() * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	mBuffer = context->CreateBuffer();

	auto usage = Render::BufferUsage::BUFFER_USAGE_VERTEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	mBuffer->Create(size, flags);
	mBuffer->Allocate(false);
}

} /* namespace Core */
