/*
 * Buffer.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "GHIBuffer.h"
#include <cassert>
#include <cstring>

namespace GHI
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
	if (src != nullptr)
	{
		std::memcpy(dst, src, size);
		Unmap(offset, size);
	}
	else
	{
		Download(dst, offset, size);
	}
}

void Buffer::Write(const void* src, size_t offset, size_t size)
{
	assert(src != nullptr);
	void* dst = Map(offset, size);
	if(dst != nullptr)
	{
		std::memcpy(dst, src, size);
		Unmap(offset, size);
	}
	else
	{
		Upload(src, offset, size);
	}
}

} /* namespace Render */
