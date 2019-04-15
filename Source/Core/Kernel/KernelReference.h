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

class Reference
{
public:
	Reference(void);
	~Reference(void);

protected:
	SafeRefCount mRefCount = {};
};

template<class T>
class Ref
{
public:
	Ref(void) = default;
	~Ref(void) { Release(); }

public:
	inline bool IsNull(void) const { return mReference == nullptr; }
	inline bool IsValid(void) const { return mReference != nullptr; }

public:
	inline void Release(void)
	{

	}

protected:
	T* mReference = nullptr;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELREFERENCE_H_ */
