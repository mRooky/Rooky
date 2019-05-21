/*
 * CoreResourceManager.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#include "CoreBindingManager.h"
#include "CoreSystem.h"
#include "GHIBindingLayout.h"
#include "GHIBindingSet.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "UtilityRelease.h"


namespace Core
{

BindingManager::BindingManager(System* system):
		Interface(system)
{
}

BindingManager::~BindingManager(void)
{
	Utility::Release(mBindingSets);
	Utility::Release(mBindingLayouts);
}

GHI::BindingSet* BindingManager::CreateSet(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	GHI::BindingSet* set = factory->CreateBindingSet();
	mBindingSets.push_back(set);
	return set;
}

GHI::BindingLayout* BindingManager::CreateLayout(void)
{
	GHI::BindingLayout* layout = new GHI::BindingLayout;
	mBindingLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
