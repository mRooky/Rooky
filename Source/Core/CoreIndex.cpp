/*
 * CoreIndex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreIndex.h"
#include "CoreBufferManager.h"
#include "CoreSystem.h"

#include "RenderElement.h"
#include "RenderBuffer.h"
#include "RenderInline.h"
#include "RenderDevice.h"
#include "RenderFactory.h"

#include <iostream>

namespace Core
{

Index::Index(BufferManager* creator):
		mCreator(creator)
{
}

Index::~Index(void)
{
	mCount = 0;
	mType = Render::IndexType::INDEX_TYPE_UNKNOWN;
}

void Index::Create(Render::IndexType type, uint32_t count, Render::AllocateType allocate)
{
	mType = type;
	mCount = count;
	CreateRenderBuffer(allocate);
	mDrawIndexed.SetIndexCount(mCount);
	std::cout << "Create Index Type : " << Render::GetIndexTypeName(mType) << std::endl;
}

void Index::CreateRenderBuffer(Render::AllocateType allocate)
{
	size_t size = Render::GetIndexTypeSize(mType) * mCount;
	assert(size > 0);
	auto buffer_usage = Render::ResourceUsage::GetBufferUsage(true);
	buffer_usage.allocate = allocate;
	buffer_usage.bufferUsage.IndexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	Render::Device* device = system->GetDevice();
	Render::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<Render::Buffer*>(mResource)->Create(size, buffer_usage);
}

} /* namespace Core */
