/*
 * =====================================================================================
 *
 *       Filename:  KernelRandom.cpp
 *
 * =====================================================================================
 */

#include "KernelRandom.h"
#include "KernelAlign.h"
#include <random>
#include <iostream>


namespace Kernel
{

void RandomBytes(void* dest, size_t size)
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

}

