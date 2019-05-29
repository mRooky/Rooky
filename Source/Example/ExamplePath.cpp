/*
 * ExampleRenderPass.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "ExamplePath.h"

#include "../Core/CoreSubPass.h"
#include <cassert>

namespace Example
{

Path::Path(void)
{
}

Path::~Path(void)
{
	delete mPass;
	mPass = nullptr;
	mThread = nullptr;
	mViewport = nullptr;
}

void Path::CreateRenderPass(void)
{
	assert(mSystem != nullptr);
	mPass = new Core::Pass(mSystem);
}

void Path::CreateViewport(void)
{
	assert(mScene != nullptr);
	assert(mWindow != nullptr);
	mScene->CreateSwapChain(mWindow);
	mViewport = mScene->CreateViewport();
}

void Path::CreateRenderThread(size_t count)
{
	assert(mViewport != nullptr);
	mViewport->CreateThread(count);
	mThread = mViewport->GetThread();
}

} /* namespace Example */
