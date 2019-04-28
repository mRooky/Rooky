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

#ifdef MULTI_THREAD_REFERENCE_COUNT
	typedef std::atomic<uint32_t> RefCountType;
#else
	typedef uint32_t RefCountType;
#endif

class SafeRefCount
{
public:
	SafeRefCount(void) = default;
	~SafeRefCount(void) = default;

public:
	inline uint32_t IncRef(void) { return ++mRefCount; }
	inline uint32_t DecRef(void) { return --mRefCount; }

protected:
	RefCountType mRefCount = 0u;

};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_ */
