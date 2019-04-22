/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "GHIBuffer.h"
#include "GHIDevice.h"
#include "GHIDrawIndirect.h"
#include "GHIFactory.h"
#include "GHIUsageType.h"
#include <cassert>

namespace GHI
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
	UsageType resource_usage;
	resource_usage.cpuAccess = TRUE;
	resource_usage.indirectBuffer = TRUE;
	mBuffer = device->GetFactory()->CreateBuffer();
	mBuffer->Create(size, resource_usage);
}

} /* namespace Render */
