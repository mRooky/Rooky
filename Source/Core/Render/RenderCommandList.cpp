/*
 * RenderCommandList.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "RenderCommandList.h"

namespace Render
{

CommandList::CommandList(CommandPool* pool):
		mCommandPool(pool)
{
}

CommandList::~CommandList(void)
{
}

} /* namespace Render */
