/*
 * KernelRandom.h
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELRANDOM_H_
#define SOURCE_CORE_KERNEL_KERNELRANDOM_H_

#include <cstddef>

namespace Kernel
{

void RandomBytes(void* dest, size_t size);

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELRANDOM_H_ */
