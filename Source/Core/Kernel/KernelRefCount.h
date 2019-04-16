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

public:
	inline uint32_t IncRef(void) { return ++mRefCount; }
	inline uint32_t DecRef(void) { return --mRefCount; }

protected:
	std::atomic<uint32_t> mRefCount = {0u};
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_ */
