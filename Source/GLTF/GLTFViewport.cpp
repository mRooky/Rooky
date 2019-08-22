/*
 * =====================================================================================
 *
 *       Filename:  GLTFViewport.cpp
 *
 * =====================================================================================
 */
#include "GLTFViewport.h"
#include "GLTFRender.h"
#include "GLTFManager.h"
#include "../Core/GHI/GHIDevice.h"
#include "../Core/GHI/GHIFactory.h"
#include "../Core/GHI/GHISwapChain.h"

namespace GLTF
{

Viewport::Viewport(Render* parent):
	mParent(parent)
{
}

Viewport::~Viewport(void)
{
	mParent = nullptr;
	delete mSwapChain;
	mSwapChain = nullptr;
}

void Viewport::Init(Platform::Window* window)
{
	CreateSwapChian(window);
}

void Viewport::CreateSwapChian(Platform::Window* window)
{
	auto manager = mParent->GetManager();
	auto device = manager->GetDevice();
	auto factory = device->GetFactory();
	mSwapChain = factory->CreateSwapChain();
	mSwapChain->Create(window);
}

}

