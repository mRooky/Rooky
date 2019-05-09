/*
 * KernelDefine.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELDEFINE_H_
#define SOURCE_CORE_KERNEL_KERNELDEFINE_H_

namespace Kernel
{

#ifdef __linux__
static constexpr char PathToken = '/';
#else
static constexpr char PathToken = '\\';
#endif

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELDEFINE_H_ */
