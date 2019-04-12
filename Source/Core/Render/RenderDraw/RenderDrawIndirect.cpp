/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "RenderDevice.h"
#include "RenderDrawIndirect.h"
#include "RenderBuffer.h"
#include "RenderFactory.h"
#include "RenderUsageType.h"
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

void DrawIndirect::Create(Device* device, size_t size)
{
	assert(mBuffer == nullptr);
	mSize = size;
	Render::UsageType resource_usage;
	resource_usage.cpuAccess = TRUE;
	resource_usage.indirectBuffer = TRUE;
	mBuffer = device->GetFactory()->CreateBuffer();
	mBuffer->Create(size, resource_usage);
}

} /* namespace Render */
