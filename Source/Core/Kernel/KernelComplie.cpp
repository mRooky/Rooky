/*
 * KernelComplie.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "KernelString.h"
#include <iostream>
#include <cassert>

void ComplieTest(const char* chars)
{
	assert(chars != nullptr);
	Kernel::String mString = chars;
	std::cout << mString.GetHash() << std::endl;
}


