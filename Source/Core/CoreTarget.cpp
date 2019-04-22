/*
 * CoreTarget.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIImage.h"
#include "CoreTarget.h"
#include "CoreTextureManager.h"
#include "CoreSystem.h"

#include <cassert>
#include <iostream>

namespace Core
{

Target::Target(TextureManager* manager):
		mManager(manager)
{
	assert(mManager != nullptr);
}

Target::~Target(void)
{
	mManager = nullptr;
}

void Target::Create(const GHI::ImageLayout& layout, const GHI::UsageType& usage)
{
	assert(mResource == nullptr);
	auto system = mManager->GetSystem();
	auto device = system->GetDevice();
	auto factory = device->GetFactory();
	mResource = factory->CreateImage();
	static_cast<GHI::Image*>(mResource)->Create(layout, usage);
	std::cout << "Image Width " << layout.extent.width << std::endl;
	std::cout << "Image Height " << layout.extent.height << std::endl;
}

} /* namespace Core */
