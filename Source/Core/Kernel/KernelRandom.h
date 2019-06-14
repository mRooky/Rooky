/*
 * KernelRandom.h
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELRANDOM_H_
#define SOURCE_CORE_KERNEL_KERNELRANDOM_H_

#include "KernelAlign.h"
#include <random>
#include <iostream>

namespace Kernel
{

static inline void RandomBytes(void* dest, size_t size)
{
	const bool valid = (size >= 4) && IsPowerOfTow(size);
	if (valid)
	{
		std::random_device device;
		std::mt19937 mt_19937(device());
		auto ptr = reinterpret_cast<uint32_t*>(dest);
		const size_t count = size / sizeof(uint32_t);
		for (size_t i = 0; i < count; ++i)
		{
			*(ptr + i) = mt_19937();
		}
	}
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELRANDOM_H_ */
