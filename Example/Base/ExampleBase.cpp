/*
 * ExampleBase.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "ExampleBase.h"
#include "Platform/XCB/XCBWindow.h"
#include <cassert>

namespace Example
{

Base::Base(void)
{
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Initialize(true);
}

Base::~Base(void)
{
	delete mWindow;
	mWindow = nullptr;
	Render::DestroyContext(mContext);
}

int32_t Base::ShowModal(void)
{
	assert(mWindow != nullptr);
	assert(mContext != nullptr);
	bool done = false;
	while (!done)
	{
		done = mWindow->HandleEvent();
	}
	return 0;
}

void Base::CreateWindow(const char* title)
{
	mWindow = new XCB::Window;
	mWindow->Create(1280, 800);
	mWindow->SetTitle(title);
}

} /* namespace Example */
