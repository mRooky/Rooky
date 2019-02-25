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

void Vertex::Create(std::vector<Render::Element> elements, uint32_t count, Render::HeapAccess access)
{
	mCount = count;
	mDeclaration = new Render::Declaration;
	mDeclaration->Create(elements);
	size_t size = mDeclaration->GetStride() * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_VERTEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Buffer::Create(size, flags, access);
}

} /* namespace Core */
