/*
 * CoreBuffer.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "CoreBuffer.h"
#include "GHI/GHIBuffer.h"
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

} /* namespace Core */
