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
	HashObject(void);
	virtual ~HashObject(void);

protected:
	size_t mHash = 0;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELHASHOBJECT_H_ */
