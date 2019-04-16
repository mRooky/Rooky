/*
 * KernelComplie.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "KernelString.h"
#include <iostream>
#include <cassert>

namespace Kernel
{
void StringHash(const char* chars)
{
	assert(chars != nullptr);
	Kernel::String mString = chars;
	std::cout << mString.Char() << " Hash [" << mString.GetHash() << "]" << std::endl;
}
}

