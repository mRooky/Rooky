/*
 * Reference.h
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELREFERENCE_H_
#define SOURCE_CORE_KERNEL_KERNELREFERENCE_H_

#include "KernelRefCount.h"

namespace Kernel
{

template<typename T>
class Reference
{
	typedef T RefCountType;
public:
	Reference(void);
	~Reference(void);

protected:
	RefCountType mRefCount = {};
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFERENCE_H_ */
