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
	mCount = 0;
	mElement = nullptr;
}

void Vertex::Create(Render::Element* element, uint32_t count)
{
	mCount = count;
	mElement = element;

	size_t size = element->GetStride() * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsage::BUFFER_USAGE_VERTEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, false);
}

} /* namespace Core */
