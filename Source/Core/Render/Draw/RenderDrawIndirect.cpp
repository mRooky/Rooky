/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include <Draw/RenderDrawIndirect.h>
#include "RenderBuffer.h"
#include "RenderContext.h"
#include "RenderFactory.h"
#include "RenderUsage.h"
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
	auto resource_usage = Render::ResourceUsage::GetBufferUsage(true);
	resource_usage.bufferUsage.IndirectBuffer = 1;
	mBuffer = context->GetFactory()->CreateBuffer();
	mBuffer->Create(size, resource_usage);
}

} /* namespace Render */
