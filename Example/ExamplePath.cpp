/*
 * ExampleRenderPass.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "ExamplePath.h"

#include "CorePass.h"

#include <cassert>

namespace Example
{

Path::Path(void)
{
}

Path::~Path(void)
{
	delete mPath;
	mPath = nullptr;
	mThread = nullptr;
	mViewport = nullptr;
}

void Path::CreateRenderPath(void)
{
	assert(mSystem != nullptr);
	mPath = new Core::Path(mSystem);
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
