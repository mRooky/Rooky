/*
 * CoreScene.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreScene.h"
#include "CoreSystem.h"

namespace Core
{

Scene::Scene(void)
{
	mSystem = new System;
	mSystem->Create();
}

Scene::~Scene(void)
{
	delete mSystem;
	mSystem = nullptr;
}

} /* namespace Core */
