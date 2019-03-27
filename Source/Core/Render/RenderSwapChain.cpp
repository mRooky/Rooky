/*
 * RenderSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "RenderSwapChain.h"
#include "RenderImage.h"

namespace Render
{

SwapChain::SwapChain(Device* device):
		Object(device)
{
}

SwapChain::~SwapChain(void)
{
	for (auto buffer : mRenderBuffers)
	{
		delete buffer;
	}
	mRenderBuffers.clear();
}

} /* namespace Render */
