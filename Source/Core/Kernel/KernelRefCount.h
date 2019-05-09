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

template<typename T>
class RefCount
{
	typedef T CountType;
public:
	RefCount(void) = default;
	~RefCount(void) = default;

public:
	inline uint32_t IncRef(void) { return ++mRefCount; }
	inline uint32_t DecRef(void) { return --mRefCount; }

protected:
	CountType mRefCount = 0u;

};

// Common
typedef RefCount<uint32_t> LockFreeRefCount;

// Thread Safety
typedef std::atomic<uint32_t> AtomicCountType;
typedef RefCount<AtomicCountType> SafeRefCount;

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFCOUNT_H_ */
