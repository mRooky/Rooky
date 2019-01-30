/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CoreViewport.h"
#include "RenderImage.h"
#include "RenderSwapChain.h"

namespace Core
{

Viewport::Viewport(void)
{
}

Viewport::~Viewport(void)
{
	delete mSwapChain;
	mSwapChain = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::Initailize(Platform::Window* window, bool depthStencil)
{
	CreateSwapChain(window);
	if (depthStencil)
	{
		CreateDepthStencil();
	}
}

void Viewport::CreateSwapChain(Platform::Window* window)
{

}

void Viewport::CreateDepthStencil(void)
{

}

} /* namespace Core */
