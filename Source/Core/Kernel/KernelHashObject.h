/*
 * KernelObject.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_
#define SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_

#include <cstddef>

namespace Kernel
{

class HashObject
{
public:
	HashObject(void) = default;
	virtual ~HashObject(void) = default;

public:
	virtual void CalcHash(void) = 0;

public:
	inline size_t GetHash(void) const { return mHash; }

protected:
	size_t mHash = 0;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_ */
