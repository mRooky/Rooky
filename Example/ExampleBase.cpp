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
	delete mScene;
	mScene = nullptr;
	mSystem = nullptr;
}

void Base::Initialize(void)
{
	CreateWindow("Base Window");
	CreateScene();
}

void Base::CreateWindow(const char* title)
{
	assert(mWindow == nullptr);
	mWindow = new XCB::Window;
	mWindow->Create(1280, 800);
	mWindow->SetTitle(title);
}

void Base::CreateScene(void)
{
	mScene = new Core::Scene;
	mSystem = mScene->GetSystem();
}

} /* namespace Example */
