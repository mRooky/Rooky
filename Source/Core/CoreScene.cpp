/*
 * CoreScene.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreScene.h"
#include "CoreSystem.h"
#include "CoreViewport.h"

#include "UtilityRelease.h"

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
	Utility::Release(mViewports);
	delete mSystem;
	mSystem = nullptr;
}

Viewport* Scene::CreateViewport(void)
{
	assert(mSystem != nullptr);
	Viewport* viewport = new Core::Viewport(mSystem);
	mViewports.push_back(viewport);
	return viewport;
}

} /* namespace Core */
