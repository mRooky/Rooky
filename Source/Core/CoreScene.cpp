/*
 * CoreScene.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHISwapChain.h"
#include "CoreScene.h"
#include "CoreSystem.h"
#include "CoreViewport.h"
#include "CoreCamera.h"
#include "CoreRenderable.h"

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

void Scene::Draw(Camera& camera)
{
	camera.ClearRenderable();
	const auto& frustum = camera.GetFrustum();
	for (auto renderable : mRenderables)
	{
		bool visible = renderable->IsVisible(frustum);
		if (true == visible)
		{
			camera.AppendRenderable(renderable);
		}
	}
}

} /* namespace Core */
