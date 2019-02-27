/*
 * RenderCommandList.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "RenderCommandList.h"
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
}

} /* namespace Render */
