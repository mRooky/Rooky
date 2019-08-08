/*
 * RenderPass.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "GHIFrameBuffer.h"
#include "GHIRenderPass.h"
#include <cassert>

namespace GHI
{

RenderPass::RenderPass(Device* device):
		Object(device)
{
}

RenderPass::~RenderPass(void)
{
	for (auto frame : mFrameBuffers)
	{
		delete frame;
	}
	mFrameBuffers.clear();
}

void RenderPass::AppendFormat(Format format)
{
	mFormats.push_back(format);
}

void RenderPass::RemoveFormat(size_t index)
{
	assert(index < mFormats.size());
	auto iterator = mFormats.begin();
	iterator += index;
	mFormats.erase(iterator);
}

} /* namespace Render */
