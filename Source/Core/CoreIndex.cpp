/*
 * CoreIndex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreIndex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderElement.h"
#include "RenderContext.h"
#include "RenderBuffer.h"
#include "RenderInline.h"

namespace Core
{

Index::Index(BufferManager* creator):
		Buffer(creator)
{
}

Index::~Index(void)
{
}

void Index::Create(Render::IndexType type, uint32_t count)
{
	size_t size = Render::GetIndexTypeSize(type) * count;
	assert(size > 0);
	auto context = mCreator->GetSystem()->GetContext();
	mBuffer = context->CreateBuffer();

	auto usage = Render::BufferUsage::BUFFER_USAGE_INDEX;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	mBuffer->Create(size, flags);
	mBuffer->Allocate(false);
}

} /* namespace Core */
