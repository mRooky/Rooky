/*
 * CoreUniform.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "GHIBuffer.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIUsageType.h"
#include "CoreUniform.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include <cassert>

namespace Core
{

Uniform::Uniform(BufferManager* creator):
		mCreator(creator)
{
}

Uniform::~Uniform(void)
{
}

void Uniform::Create(size_t size, GHI::UsageType usage)
{
	assert(size > 0);
	mSize = size;
	CreateRenderBuffer(usage);
}

void Uniform::CreateRenderBuffer(GHI::UsageType usage)
{
	usage.uniformBuffer = TRUE;
	usage.type = GHI::ResourceType::RESOURCE_TYPE_BUFFER;
	System* system = mCreator->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<GHI::Buffer*>(mResource)->Create(mSize, usage);
}

} /* namespace Core */
