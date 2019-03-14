/*
 * CoreTarget.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTarget.h"
#include "CoreTextureManager.h"
#include "CoreSystem.h"

#include "RenderImage.h"
#include "RenderContext.h"
#include "RenderFactory.h"

#include <cassert>

namespace Core
{

Target::Target(TextureManager* manager):
		mManager(manager)
{
	assert(mManager != nullptr);
}

Target::~Target(void)
{
	delete mImage;
	mImage = nullptr;
	mManager = nullptr;
}

void Target::Create(const Render::ImageLayout& layout)
{
	assert(mImage == nullptr);
	auto system = mManager->GetSystem();
	auto context = system->GetContext();
	auto factory = context->GetFactory();
	mImage = factory->CreateImage();
	mImage->Create(layout);
}

} /* namespace Core */
