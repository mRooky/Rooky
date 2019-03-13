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
	delete mViewport;
	mViewport = nullptr;
}

void Viewport::CreateViewport(void)
{
	assert(mSystem != nullptr);
	assert(mWindow != nullptr);
	mViewport = new Core::Viewport(mSystem);
	mViewport->Create(mWindow);
}

} /* namespace Example */
