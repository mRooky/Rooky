/*
 * KernelMemory.h
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELMEMORY_H_
#define SOURCE_CORE_KERNEL_KERNELMEMORY_H_

#include <cstring>

namespace Kernel
{

template<typename T>
static inline void ZeroMemory(T& value, size_t count = 1)
{
	size_t size = sizeof(T) * count;
	std::memset(value, 0, size);
}

template<typename T>
static inline size_t Memcpy(void* dest, const T& value)
{
	size_t size = sizeof(T);
	std::memcpy(dest, &value, size);
	return size;
}

template<typename T>
static inline size_t Memcpy(void* dest, const T* value, size_t count = 1)
{
	size_t size = sizeof(T) * count;
	std::memcpy(dest, value, size);
	return size;
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELMEMORY_H_ */
