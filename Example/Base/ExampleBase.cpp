/*
 * ExampleBase.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "ExampleBase.h"

#ifdef VK_USE_PLATFORM_XCB_KHR
#include "Platform/XCB/XCBWindow.h"
#endif

#include <cassert>

namespace Example
{

Base::Base(void)
{
}

Base::~Base(void)
{
	delete mWindow;
	mWindow = nullptr;
	delete mSystem;
	mSystem = nullptr;
}

void Base::Initialize(void)
{
	CreateWindow("Rooky Window");
	CreateSystem();
}

void Base::CreateWindow(const char* title)
{
	assert(mWindow == nullptr);
	mWindow = new XCB::Window;
	mWindow->Create(1280, 800);
	mWindow->SetTitle("Rooky Vulkan");
}

void Base::CreateSystem(void)
{
	mSystem = new Core::System;
	assert(mSystem != nullptr);
	mSystem->Create();
}

int32_t Base::ShowModal(void)
{
	assert(mWindow != nullptr);
	bool done = false;
	while (!done)
	{
		done = mWindow->HandleEvent();
	}
	return 0;
}

} /* namespace Example */
