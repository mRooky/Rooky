/*
 * CoreBuffer.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "CoreBuffer.h"
#include "RenderBuffer.h"
#include <cassert>
#include <cstring>

namespace Core
{

Buffer::Buffer(void)
{
}

Buffer::~Buffer(void)
{
}

Render::Buffer* Buffer::GetRenderBuffer(void)
{
	return static_cast<Render::Buffer*>(mResource);
}

void Buffer::Read(void* dst, size_t offset, size_t size)
{
	auto buffer = GetRenderBuffer();
	assert(dst != nullptr);
	void* src = buffer->Map(offset, size);
	assert(src != nullptr);
	std::memcpy(dst, src, size);
	buffer->Unmap(offset, size);
}

void Buffer::Write(const void* src, size_t offset, size_t size)
{
	auto buffer = GetRenderBuffer();
	assert(src != nullptr);
	void* dst = buffer->Map(offset, size);
	assert(dst != nullptr);
	std::memcpy(dst, src, size);
	buffer->Unmap(offset, size);
}

} /* namespace Core */
