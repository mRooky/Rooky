/*
 * RenderCommandPool.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "GHICommandList.h"
#include "GHICommandPool.h"

namespace GHI
{

CommandPool::CommandPool(Device* device):
		Object(device)
{
}

CommandPool::~CommandPool(void)
{
	mCommandLists.clear();
}

} /* namespace Render */
