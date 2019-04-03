/*
 * CoreUniform.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreUniform.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderUsage.h"
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

void Uniform::Create(size_t size, Render::AllocateType allocate)
{
	assert(size > 0);
	mSize = size;
	CreateRenderBuffer(allocate);
}

void Uniform::Read(void* dst, size_t offset, size_t size)
{
	assert(mResource != nullptr);
	auto buffer = static_cast<Render::Buffer*>(mResource);
	buffer->Read(dst, offset, size);
}

void Uniform::Write(const void* src, size_t offset, size_t size)
{
	assert(mResource != nullptr);
	auto buffer = static_cast<Render::Buffer*>(mResource);
	buffer->Write(src, offset, size);
}

void Uniform::CreateRenderBuffer(Render::AllocateType allocate)
{
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.UniformBuffer = TRUE;

	System* system = mCreator->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<Render::Buffer*>(mResource)->Create(mSize, buffer_usage);
}

} /* namespace Core */
