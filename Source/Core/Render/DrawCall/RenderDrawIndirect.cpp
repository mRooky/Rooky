/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "RenderDrawIndirect.h"
#include "RenderBuffer.h"
#include "RenderContext.h"
#include "RenderFactory.h"
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
	BufferUsage usage = {};
	usage.BufferUsageIndirect = 1;
	mBuffer = context->GetFactory()->CreateBuffer();
	mBuffer->Create(size, usage.BufferUsageFlags);
	Render::HeapAccess access = Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE;
	mBuffer->Allocate(access);
}

} /* namespace Render */
