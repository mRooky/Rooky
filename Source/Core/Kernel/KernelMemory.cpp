/*
 * =====================================================================================
 *
 *       Filename:  KernelMemory.cpp
 *
 * =====================================================================================
 */

#include "KernelMemory.h"

namespace Kernel
{

void Memory::Free(void)
{

	m_size = 0;
	delete[] m_memory;
	m_memory = nullptr;
}

void Memory::Allocate(size_t size, bool align)
{
	Free();
	m_size = align ? GetAlignSize(size) : size;
	m_memory = new uint8_t[m_size];
}

uint8_t* Memory::Map(size_t offset, size_t size)
{
	if (offset + size <= m_size)
	{
		return m_memory + offset;
	}

	return nullptr;
}

const uint8_t* Memory::Map(size_t offset, size_t size) const
{
	return Map(size, offset);
}

}

