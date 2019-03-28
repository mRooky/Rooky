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
	delete mThread;
	mThread = nullptr;
	mCommandLists.clear();
}

void Path::CreateRenderPath(void)
{
	assert(mSystem != nullptr);
	mPath = new Core::Path(mSystem);
}

void Path::CreateRenderThread(size_t count)
{
	mThread = new Core::Thread(mSystem);
	mThread->Create();
	for (size_t i = 0; i < count; ++i)
	{
		Render::CommandList* list = mThread->Allocate(true);
		mCommandLists.push_back(list);
	}
}

} /* namespace Example */
