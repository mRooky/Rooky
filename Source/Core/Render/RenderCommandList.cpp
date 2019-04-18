/*
 * RenderCommandList.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "RenderBindingLayout.h"
#include "RenderCommandList.h"
#include "RenderDevice.h"
#include "RenderCommandPool.h"
#include "RenderQueue.h"
#include <cassert>

namespace Render
{

CommandList::CommandList(CommandPool* pool):
		mCommandPool(pool)
{
	assert(mCommandPool != nullptr);
}

CommandList::~CommandList(void)
{
	mCommandPool = nullptr;
}

void CommandList::Submit(Queue* queue)
{
	assert(queue != nullptr);
	queue->Submit(this);
}

void CommandList::Submit(uint32_t index)
{
	Device* device = mCommandPool->GetDevice();
	Queue* queue = device->GetQueue(index);
	queue->Submit(this);
}

} /* namespace Render */
