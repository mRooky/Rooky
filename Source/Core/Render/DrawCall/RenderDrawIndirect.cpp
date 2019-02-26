/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "RenderDrawIndirect.h"
#include "RenderBuffer.h"
#include "RenderContext.h"
#include <cassert>

namespace Render
{

DrawIndirect::DrawIndirect(void)
{
	mType = DrawType::DRAW_TYPE_INDIRECT;
}

DrawIndirect::~DrawIndirect(void)
{
	delete mBuffer;
	mBuffer = nullptr;
}

void DrawIndirect::Create(Context* context, size_t size)
{
	assert(mBuffer == nullptr);
	mSize = size;
	auto usage = Render::BufferUsageFlags::BUFFER_USAGE_INDIRECT;
	uint32_t flags = context->GetUsageFlag(usage, true, true);
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	mBuffer = context->CreateBuffer();
	mBuffer->Create(size, flags, access);
}

} /* namespace Render */
