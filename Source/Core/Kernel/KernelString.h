/*
 * KernelString.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELSTRING_H_
#define SOURCE_CORE_KERNEL_KERNELSTRING_H_

#include "KernelHashObject.h"
#include <string>

namespace Kernel
{

class String : public HashObject
{
public:
	String(void);
	virtual ~String(void) override;

protected:
	std::string mString;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELSTRING_H_ */
