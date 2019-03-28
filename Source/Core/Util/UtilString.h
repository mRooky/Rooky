/*
 * UtilString.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTIL_UTILSTRING_H_
#define SOURCE_CORE_UTIL_UTILSTRING_H_

#include <string>

namespace Util
{

static inline std::string GetFileName(const std::string& file)
{
	return file.substr(file.find_last_of("/\\") + 1);
}

static inline std::string GetFileType(const std::string& file)
{
	return file.substr(file.find_last_of(".") + 1);
}

static inline std::string GetFilePath(const std::string& file)
{
	return file.substr(0, file.find_last_of("/\\") + 1);
}

} /* namespace Util */

#endif /* SOURCE_CORE_UTIL_UTILSTRING_H_ */
