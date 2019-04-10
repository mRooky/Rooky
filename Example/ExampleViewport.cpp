/*
 * ExampleViewport.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "ExampleViewport.h"

#include <cassert>

namespace Example
{

Viewport::Viewport(void)
{
}

Viewport::~Viewport(void)
{
	mViewport = nullptr;
}

void Viewport::CreateViewport(void)
{
	assert(mScene != nullptr);
	assert(mWindow != nullptr);
	mViewport = mScene->CreateViewport();
	mViewport->CreateSwapChain(mWindow);
}

} /* namespace Example */
