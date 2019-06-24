/*
 * CoreBuffer.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "CoreBuffer.h"
#include "CoreSystem.h"
#include "GHI/GHIBuffer.h"
#include "GHI/GHIDevice.h"
#include "GHI/GHIFactory.h"
#include "Manager/CoreBufferManager.h"
#include <cassert>
#include <cstring>

namespace Core
{

Buffer::Buffer(BufferManager* creator) :
	mCreator(creator)
{
}

Buffer::~Buffer(void)
{
	mCreator = nullptr;
}

void Buffer::Upload(bool merge)
{
	const size_t count = mHostMemory.GetDirtyCount();
	if (count > 0)
	{
		if (true == merge)
		{
			auto range = mHostMemory.GetMergeRange();
			const void* src = mHostMemory.GetMemoryRange(range.offset, range.size);
			Write(src, range.offset, range.size);
		}
		else
		{
			for (size_t index = 0; index < count; ++index)
			{
				const auto& range = mHostMemory.GetDirtyRange(index);
				const void* src = mHostMemory.GetMemoryRange(index);
				Write(src, range.offset, range.size);
			}
		}
		mHostMemory.ClearDirtyRange();
	}
}

void Buffer::Read(void* dst, size_t offset, size_t size)
{
	assert(mResource != nullptr);
	auto buffer = static_cast<GHI::Buffer*>(mResource);
	buffer->Read(dst, offset, size);
}

void Buffer::Write(const void* src, size_t offset, size_t size)
{
	assert(mResource != nullptr);
	auto buffer = static_cast<GHI::Buffer*>(mResource);
	buffer->Write(src, offset, size);
}

void Buffer::CreateRenderBuffer(size_t size, GHI::UsageType usage)
{
	assert(size > 0);
	System* system = mCreator->GetSystem();
	GHI::Device* device = system->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mResource = factory->CreateBuffer();
	static_cast<GHI::Buffer*>(mResource)->Create(size, usage);
}

} /* namespace Core */
