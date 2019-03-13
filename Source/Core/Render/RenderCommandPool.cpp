/*
 * RenderCommandPool.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "RenderCommandPool.h"
#include "RenderCommandList.h"

namespace Render
{

CommandPool::CommandPool(Context* context):
		Object(context)
{
}

CommandPool::~CommandPool(void)
{
	mCommandLists.clear();
}

} /* namespace Render */
