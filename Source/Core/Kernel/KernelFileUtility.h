/*
 * KernelFileUtility.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_
#define SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_

#include "KernelDefine.h"
#include "KernelString.h"
#include <fstream>

namespace Kernel
{

static inline bool DoesFileExist(const String& file)
{
	std::ifstream f(file);
	return f.good();
}

static inline String GetFileName(const String& file)
{
	return file.substr(file.find_last_of(PathToken) + 1);
}

static inline String GetFileType(const String& file)
{
	return file.substr(file.find_last_of(".") + 1);
}

static inline String GetFilePath(const String& file)
{
	return file.substr(0, file.find_last_of(PathToken) + 1);
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_ */
