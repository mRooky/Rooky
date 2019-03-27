/*
 * CoreTarget.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreTarget.h"
#include "CoreTextureManager.h"
#include "CoreSystem.h"

#include "RenderImage.h"
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

void Target::Create(const Render::ImageLayout& layout, const Render::ResourceUsage& usage)
{
	assert(mImage == nullptr);
	auto system = mManager->GetSystem();
	auto device = system->GetDevice();
	auto factory = device->GetFactory();
	mImage = factory->CreateImage();
	mImage->Create(layout, usage);
}

} /* namespace Core */
