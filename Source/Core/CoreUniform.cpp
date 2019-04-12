/*
 * CoreUniform.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreUniform.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderUsageType.h"
#include "RenderDevice.h"
#include "RenderBuffer.h"
#include "RenderFactory.h"

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

void Uniform::Create(size_t size, Render::UsageType usage)
{
	assert(size > 0);
	mSize = size;
	CreateRenderBuffer(usage);
}

void Uniform::CreateRenderBuffer(Render::UsageType usage)
{
	usage.uniformBuffer = TRUE;
	usage.type = Render::ResourceType::RESOURCE_TYPE_BUFFER;
	System* system = mCreator->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<Render::Buffer*>(mResource)->Create(mSize, usage);
}

} /* namespace Core */
