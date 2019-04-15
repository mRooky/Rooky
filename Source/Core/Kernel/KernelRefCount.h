/*
 * RefCount.h
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_
#define SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_

#include <atomic>

namespace Kernel
{

class SafeRefCount
{
public:
	SafeRefCount(void) = default;
	~SafeRefCount(void) = default;

protected:
	std::atomic<int32_t> mRefCoumt;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_ */
