/*
 * CoreIndex.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreIndex.h"
#include "Manager/CoreBufferManager.h"
#include "CoreSystem.h"
#include "GHI/GHIBuffer.h"
#include "GHI/GHIDevice.h"
#include "GHI/GHIFactory.h"
#include "GHI/GHIInline.h"

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
	mType = GHI::IndexType::INDEX_TYPE_UNKNOWN;
}

void Index::Create(GHI::IndexType type, uint32_t count)
{
	GHI::UsageType usage;
	usage.read = TRUE;
	usage.write = TRUE;
	usage.type = GHI::ResourceType::BUFFER;
	Create(type, count, usage);
}

void Index::Create(GHI::IndexType type, uint32_t count, GHI::UsageType usage)
{
	mType = type;
	mCount = count;
	CreateRenderBuffer(usage);
	mDrawIndexed.SetIndexCount(mCount);
	std::cout << "Create Index Type : " << GHI::GetIndexTypeName(mType) << std::endl;
}

size_t Index::GetSizeInByte(void)
{
	const size_t size = GHI::GetIndexTypeSize(mType) * mCount;
	return size;
}

void Index::CreateRenderBuffer(GHI::UsageType usage)
{
	size_t size = GHI::GetIndexTypeSize(mType) * mCount;
	assert(size > 0);
	usage.indexBuffer = TRUE;

	System* system = mCreator->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<GHI::Buffer*>(mResource)->Create(size, usage);
}

} /* namespace Core */
