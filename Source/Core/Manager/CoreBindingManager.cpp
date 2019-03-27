/*
 * CoreResourceManager.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreBindingManager.h"
#include "CoreSystem.h"
#include "RenderFactory.h"

#include "UtilRelease.h"

namespace Core
{

BindingManager::BindingManager(System* system):
		Object(system)
{
}

BindingManager::~BindingManager(void)
{
	Util::Release(mBindingLayouts);
}

Render::BindingLayout* BindingManager::CreateLayout(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::BindingLayout* layout = factory->CreateBindingLayout();
	mBindingLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
