/*
 * UtilData.cpp
 *
 *  Created on: Jan 18, 2019
 *      Author: rookyma
 */

#include "UtilityByteBuffer.h"
#include <memory>
#include <cassert>
#include <cstring>

namespace Utility
{

ByteBuffer::ByteBuffer(void)
{
}

ByteBuffer::~ByteBuffer(void)
{
	Clear();
}

void ByteBuffer::Clear(void)
{
	std::free(m_bytes);
	m_size = 0;
	m_bytes = nullptr;
}

void ByteBuffer::Move(ByteBuffer& other)
{
	Clear();
	if (other.m_size > 0)
	{
		m_size = other.m_size;
		m_bytes = other.m_bytes;
		other.m_size = 0;
		other.m_bytes = nullptr;
	}
}

void ByteBuffer::Copy(const ByteBuffer& other)
{
	Clear();
	if (other.m_size > 0)
	{
		m_size = other.m_size;
		m_bytes = static_cast<uint8_t*>(std::malloc(m_size));
		std::memcpy(m_bytes, other.m_bytes, m_size);
	}
}

uint8_t* ByteBuffer::Allocate(size_t size)
{
	assert(size > 0);
	assert(m_bytes == nullptr);
	m_size = size;
	m_bytes = static_cast<uint8_t*>(std::malloc(size));
	return m_bytes;
}

} /* namespace Util */
