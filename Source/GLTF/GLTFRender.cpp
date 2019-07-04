/*
 * =====================================================================================
 *
 *       Filename:  GLTFRender.cpp
 *
 * =====================================================================================
 */
#include "GLTFRender.h"
#include "GLTFManager.h"
#include "../Platform/XCB/XCBWindow.h"
#include "../Core/GHI/GHIDevice.h"
#include "../Core/GHI/GHIFactory.h"
#include "../Core/GHI/GHISwapChain.h"
#include <cassert>

namespace GLTF
{

Render::Render(void)
{

}

Render::~Render(void)
{

}

Platform::Window* Render::Init(uint32_t width, uint32_t height, const char* title)
{
	CreateWindow(width, height, title);
	CreateSwapChain();
	assert(mWindow != nullptr);
	return mWindow;
}

void Render::CreateWindow(uint32_t width, uint32_t height, const char* title)
{
	assert(mWindow == nullptr);
	mWindow = new XCB::Window;
	mWindow->Create(width, height);
	mWindow->SetTitle(title);
}

void Render::CreateSwapChain(void)
{
	auto device = mManager->GetDevice();
	auto factory = device->GetFactory();
	mSwapChain = factory->CreateSwapChain();
	mSwapChain->Create(mWindow);
}

}

