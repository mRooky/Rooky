/*
 * KernelObject.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_
#define SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_

#include "KernelHash.h"

namespace Kernel
{

class HashObject
{
public:
	HashObject(void) = default;
	virtual ~HashObject(void) = default;

public:
	inline const Hash& GetHash(void) const
	{
		return mHash;
	}

protected:
	mutable Hash mHash = 0;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_ */
