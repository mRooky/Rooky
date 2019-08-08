/*
 * KernelAutoHandle.h
 *
 *  Created on: Apr 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELHANDLE_H_
#define SOURCE_CORE_KERNEL_KERNELHANDLE_H_

namespace Kernel
{

template<class T>
class Handle final
{
public:
	Handle(void);
	~Handle(void);

public:
	inline bool IsNull(void) const
	{
		return mReference == nullptr;
	}

	inline bool IsValid(void) const
	{
		return mReference != nullptr;
	}

protected:
	T* mReference = nullptr;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELHANDLE_H_ */
