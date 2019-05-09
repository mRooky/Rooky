/*
 * KernelString.cpp
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#include "KernelString.h"
#include <iostream>

namespace Kernel
{

void HashString::Print(void)
{
	std::cout << mString << " Hash [" << GetHash() << "]" << std::endl;
}

}
