/*
 * KernelArray.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELARRAY_H_
#define SOURCE_CORE_KERNEL_KERNELARRAY_H_

#include "KernelUtility.h"

#include <array>

namespace Kernel
{

template<typename T, size_t N>
class Array
{
public:
	Array(void) = default;
	~Array(void) = default;

private:
	size_t m_current = 0;
	std::array<T, N> m_elements;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELARRAY_H_ */
