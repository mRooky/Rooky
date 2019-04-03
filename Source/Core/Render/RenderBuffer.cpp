/*
 * Buffer.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "RenderBuffer.h"
#include <cassert>
#include <cstring>

namespace Render
{

Buffer::Buffer(Device* device):
		Memory(device)
{
	mType = ResourceType::RESOURCE_TYPE_BUFFER;
}

Buffer::~Buffer(void)
{
}

void Buffer::Read(void* dst, size_t offset, size_t size)
{
	assert(dst != nullptr);
	void* src = Map(offset, size);
	assert(src != nullptr);
	std::memcpy(dst, src, size);
	Unmap(offset, size);
}

void Buffer::Write(const void* src, size_t offset, size_t size)
{
	assert(src != nullptr);
	void* dst = Map(offset, size);
	assert(dst != nullptr);
	std::memcpy(dst, src, size);
	Unmap(offset, size);
}

} /* namespace Render */
