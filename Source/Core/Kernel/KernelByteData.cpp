/*
 * KernelByteData.cpp
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#include "KernelByteData.h"
#include "KernelMemory.h"
#include "KernelAlign.h"

namespace Kernel
{

ByteData::ByteData(void)
{
}

ByteData::~ByteData(void)
{
	Clear();
}

void ByteData::Clear(void)
{
	std::free(m_bytes);
	m_size = 0;
	m_bytes = nullptr;
}

void ByteData::Move(ByteData& other)
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

void ByteData::Copy(const ByteData& other)
{
	Clear();
	if (other.m_size > 0)
	{
		m_size = other.m_size;
		m_bytes = static_cast<uint8_t*>(std::malloc(m_size));
		std::memcpy(m_bytes, other.m_bytes, m_size);
	}
}

uint8_t* ByteData::Allocate(size_t size)
{
	assert(size > 0);
	assert(m_bytes == nullptr);
	m_size = size;
	m_bytes = static_cast<uint8_t*>(std::malloc(size));
	return m_bytes;
}

} /* namespace Kernel */
