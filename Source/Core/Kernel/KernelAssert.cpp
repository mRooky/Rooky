/*
 * KernelAssert.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "KernelAssert.h"
#include <cassert>

namespace Kernel
{

void Assert(bool result, const char* file, const char* line, const char* func)
{
	assert(false);
}

} /* namespace Kernel */
