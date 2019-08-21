/*
 * KernelFileUtility.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_
#define SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_

#include "KernelDefine.h"
#include <fstream>

namespace Kernel
{

static inline bool DoesFileExist(const std::string& file)
{
	std::ifstream f(file);
	return f.good();
}

static inline std::string GetFileName(const std::string& file)
{
	return file.substr(file.find_last_of(PathToken) + 1);
}

static inline std::string GetFileType(const std::string& file)
{
	return file.substr(file.find_last_of(".") + 1);
}

static inline std::string GetFilePath(const std::string& file)
{
	return file.substr(0, file.find_last_of(PathToken) + 1);
}

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELFILEUTILITY_H_ */
