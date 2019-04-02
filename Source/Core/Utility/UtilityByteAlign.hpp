/*
 * UtilByteAlignment.hpp
 *
 *  Created on: Mar 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYBYTEALIGN_HPP_
#define SOURCE_CORE_UTILITY_UTILITYBYTEALIGN_HPP_

#include <cstddef>
#include <type_traits>
#include <cassert>
#include <cstdlib>

namespace Utility
{

template<typename T>
static inline bool IsPowerOfTow(T value)
{
	static_assert(std::is_integral<T>::value, "Integral required");
	return value > 0 && (value & (value - 1)) == 0;
}

static inline size_t GetAlignSize(size_t size, size_t alignment)
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

}

#endif /* SOURCE_CORE_UTILITY_UTILITYBYTEALIGN_HPP_ */