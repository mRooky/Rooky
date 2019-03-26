/*
 * CoreResourceManager.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: rookyma
 */

#include "CoreBindingManager.h"
#include "CoreSystem.h"
#include "RenderContext.h"
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
	auto context = mSystem->GetContext();
	auto factory = context->GetFactory();
	Render::BindingLayout* layout = factory->CreateBindingLayout();
	mBindingLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
