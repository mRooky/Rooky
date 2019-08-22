/*
 * KernalUtility.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNALUTILITY_H_
#define SOURCE_CORE_KERNEL_KERNALUTILITY_H_

#include <cstddef>
#include <cassert>

namespace Kernel
{

static inline bool Not(bool flag)
{
	return !flag;
}

template<typename T>
static inline T Bit(size_t pos)
{
	assert(pos < sizeof(T) * 8);
	return static_cast<T>(1 << pos);
}

}

#endif /* SOURCE_CORE_KERNEL_KERNALUTILITY_H_ */
