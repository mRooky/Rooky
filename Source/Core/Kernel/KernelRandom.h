/*
 * KernelRandom.h
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELRANDOM_H_
#define SOURCE_CORE_KERNEL_KERNELRANDOM_H_

#include <cstddef>
#include <random>

namespace Kernel
{

template<typename T>
void RandomBytes(void* dest, size_t size)
{
	std::random_device rd;
	const T lower = 0;
	const T upper = static_cast<T>(~0);
	std::uniform_int_distribution<T> dist(lower, upper);
	auto buffer = reinterpret_cast<T*>(dest);
	const size_t count = size / sizeof(T);
	for (size_t i = 0; i < count; ++i)
	{
		*(buffer + i) = dist(rd);
	}
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELRANDOM_H_ */
