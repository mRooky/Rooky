/*
 * KernelMemory.h
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELMEMORY_H_
#define SOURCE_CORE_KERNEL_KERNELMEMORY_H_

#include "KernelAlign.h"
#include <cstdint>

namespace Kernel
{

class Memory
{
public:
	Memory(void) = default;
	~Memory(void)
	{
		Free();
	}

public:
	void Free(void);
	void Allocate(size_t size, bool align = false);

public:
	uint8_t* Map(size_t offset, size_t size);
	const uint8_t* Map(size_t offset, size_t size) const;

public:
	inline operator void* (void)
	{
		return m_memory;
	}

	inline operator const void* (void) const
	{
		return m_memory;
	}

public:
	inline size_t GetSize(void) const
	{
		return m_size;
	}

	inline bool IsValid(void) const
	{
		return m_memory != nullptr;
	}

private:
	size_t m_size = 0;
	uint8_t* m_memory = nullptr;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELMEMORY_H_ */
