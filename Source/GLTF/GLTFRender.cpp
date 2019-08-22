/*
 * =====================================================================================
 *
 *       Filename:  GLTFRender.cpp
 *
 * =====================================================================================
 */
#include "GLTFRender.h"
#include "GLTFManager.h"
#include "GLTFViewport.h"
#include "../Core/GHI/GHIDevice.h"
#include "../Core/GHI/GHIFactory.h"
#include "../Platform/XCB/XCBWindow.h"
#include <cassert>

namespace GLTF
{

Render::Render(void)
{

}

Render::~Render(void)
{
	delete mViewport;
	mViewport = nullptr;
	delete mManager;
	mManager = nullptr;
}

Platform::Window* Render::Init(uint32_t width, uint32_t height, const char* title)
{
	CreateWindow(width, height, title);
	assert(mWindow != nullptr);
	CreateManager();
	CreateViewport();
	return mWindow;
}

void Render::CreateWindow(uint32_t width, uint32_t height, const char* title)
{
	assert(mWindow == nullptr);
	mWindow = new XCB::Window;
	mWindow->Create(width, height);
	mWindow->SetTitle(title);
}

void Render::CreateManager(void)
{
	mManager = new Manager(this);
	mManager->Init();
}

void Render::CreateViewport(void)
{
	assert(nullptr != mWindow);
	mViewport = new Viewport(this);
	mViewport->Init(mWindow);
}

}

