/*
 * CoreScene.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreScene.h"
#include "CoreSystem.h"
#include "CoreViewport.h"

#include "RenderFactory.h"
#include "RenderDevice.h"
#include "RenderSwapChain.h"

#include "UtilityRelease.h"
#include "UtilitySearch.h"

#include <cassert>

namespace Core
{

Scene::Scene(void)
{
	mSystem = new System;
	mSystem->Create();
}

Scene::~Scene(void)
{
	delete mSwapChain;
	mSwapChain = nullptr;
	Utility::Release(mViewports);
	delete mSystem;
	mSystem = nullptr;
	mRenderables.clear();
}

void Scene::CreateSwapChain(Platform::Window* window)
{
	auto device = mSystem->GetDevice();
	mSwapChain = device->GetFactory()->CreateSwapChain();
	mSwapChain->Create(window);
}

Viewport* Scene::CreateViewport(void)
{
	Viewport* viewport = new Core::Viewport(this);
	mViewports.push_back(viewport);
	return viewport;
}

void Scene::AddRenderable(Renderable* renderable)
{
	auto iterator = Utility::Find(mRenderables, renderable);
	if (iterator == mRenderables.end())
	{
		mRenderables.push_back(renderable);
	}
}

} /* namespace Core */
