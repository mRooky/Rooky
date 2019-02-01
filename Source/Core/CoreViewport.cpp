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
	delete mDepthStencil;
	mDepthStencil = nullptr;
}

void Viewport::Initialize(bool depthStencil)
{
	if (depthStencil)
	{
		CreateDepthStencil();
	}
}

void Viewport::CreateDepthStencil(void)
{
}

} /* namespace Core */
