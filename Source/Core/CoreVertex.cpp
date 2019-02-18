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
	delete mElement;
	mElement = nullptr;
}

void Vertex::Create(std::vector<Render::Format> semantics, uint32_t count, Render::HeapAccess access)
{
	mCount = count;
	mElement = new Render::Element;

	for (auto semantic : semantics)
	{
		mElement->AppendSemantic(semantic);
	}

	size_t size = mElement->GetStride() * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_VERTEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, access);
}

} /* namespace Core */
