/*
 * KernelAlignment.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELALIGNMENT_H_
#define SOURCE_CORE_KERNEL_KERNELALIGNMENT_H_

#include <cstddef>
#include <type_traits>
#include <cassert>
#include <cstdlib>

namespace Kernel
{

template<typename T>
static inline bool IsPowerOfTow(T value)
{
	static_assert(std::is_integral<T>::value, "Integral required");
	return value > 0 && (value & (value - 1)) == 0;
}

static inline size_t GetAlignSize(size_t size, size_t alignment = 2)
{
	assert(IsPowerOfTow(alignment));
	return (size + alignment - 1) & ~(alignment - 1);
}

static inline void* AlignAllocate(size_t size, size_t alignment)
{
	size_t align_size = GetAlignSize(size, alignment);
	assert(IsPowerOfTow(align_size));
	return std::malloc(align_size);
}

static inline void AlignFree(void* memory)
{
	std::free(memory);
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELALIGNMENT_H_ */
