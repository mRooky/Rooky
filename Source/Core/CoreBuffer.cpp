/*
 * CoreBuffer.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreBuffer.h"
#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderBuffer.h"
#include "RenderFactory.h"
#include "RenderDevice.h"

#include <cassert>
#include <cstring>

namespace Core
{

Buffer::Buffer(BufferManager* creator):
		mCreator(creator)
{
	assert(mCreator != nullptr);
}

Buffer::~Buffer(void)
{
	delete mBuffer;
	mBuffer = nullptr;
	mCreator = nullptr;
}

void Buffer::Create(size_t size, Render::ResourceUsage usage)
{
	auto device = mCreator->GetSystem()->GetDevice();
	mBuffer = device->GetFactory()->CreateBuffer();
	mBuffer->Create(size, usage);
}

void Buffer::Read(void* dst, size_t offset, size_t size)
{
	assert(dst != nullptr);
	void* src = mBuffer->Map(offset, size);
	assert(src != nullptr);
	std::memcpy(dst, src, size);
	mBuffer->Unmap(offset, size);
}

void Buffer::Write(const void* src, size_t offset, size_t size)
{
	assert(src != nullptr);
	void* dst = mBuffer->Map(offset, size);
	assert(dst != nullptr);
	std::memcpy(dst, src, size);
	mBuffer->Unmap(offset, size);
}

} /* namespace Core */
