/*
 * CoreViewport.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CoreViewport.h"
#include "RenderImage.h"

namespace Core
{

Viewport::Viewport(void)
{
}

Viewport::~Viewport(void)
{
	mSurface = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::Initialize(Render::Surface* surface, bool depthStencil)
{
	mSurface = surface;
	if (depthStencil)
	{
		CreateDepthStencil();
	}
}

void Viewport::CreateDepthStencil(void)
{
}

} /* namespace Core */
