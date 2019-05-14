/*
 * KernelAssert.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELASSERT_H_
#define SOURCE_CORE_KERNEL_KERNELASSERT_H_

namespace Kernel
{

void Assert(bool result, const char* file, const char* line, const char* func);

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELASSERT_H_ */
