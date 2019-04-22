/*
 * RenderSwapChain.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "GHIImage.h"
#include "GHISwapChain.h"

namespace GHI
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
