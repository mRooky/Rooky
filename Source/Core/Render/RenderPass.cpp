/*
 * RenderPass.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderPass.h"
#include "RenderFrameBuffer.h"
#include <cassert>

namespace Render
{

Pass::Pass(Context* context):
		Object(context)
{
}

Pass::~Pass(void)
{
	for (auto frame : mFrameBuffers)
	{
		delete frame;
	}
	mFrameBuffers.clear();
}

void Pass::AppendFormat(Format format)
{
	mFormats.push_back(format);
}

void Pass::RemoveFormat(size_t index)
{
	assert(index < mFormats.size());
	auto iterator = mFormats.begin();
	for (size_t i = 0; i < index; ++i)
	{
		++iterator;
	}
	mFormats.erase(iterator);
}

} /* namespace Render */
