/*
 * RenderDrawIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "GHIDrawIndirect.h"

#include "../GHIBuffer.h"
#include "../GHIDevice.h"
#include "../GHIFactory.h"
#include "../GHIResourceUsage.h"
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
	ResourceUsage usage;
	usage.memoryType.cpuAccess = TRUE;
	usage.bufferUsage.indirectBuffer = TRUE;
	mBuffer = device->GetFactory()->CreateBuffer();
	mBuffer->Create(size, usage);
}

} /* namespace Render */
