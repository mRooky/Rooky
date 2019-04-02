/*
 * CoreResourceManager.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#include "UtilityRelease.h"
#include "CoreBindingManager.h"
#include "CoreSystem.h"

#include "RenderBindingLayout.h"
#include "RenderBindingSet.h"
#include "RenderDevice.h"
#include "RenderFactory.h"

namespace Core
{

BindingManager::BindingManager(System* system):
		Object(system)
{
}

BindingManager::~BindingManager(void)
{
	Utility::Release(mBindingSets);
	Utility::Release(mBindingLayouts);
}

Render::BindingSet* BindingManager::CreateSet(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::BindingSet* set = factory->CreateBindingSet();
	mBindingSets.push_back(set);
	return set;
}

Render::BindingLayout* BindingManager::CreateLayout(void)
{
	Render::BindingLayout* layout = new Render::BindingLayout;
	mBindingLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
