/*
 * UtilString.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYSTRING_H_
#define SOURCE_CORE_UTILITY_UTILITYSTRING_H_

#include <string>
#include <fstream>

namespace Utility
{

static inline bool DoesFileExist(const std::string& file)
{
	std::ifstream f(file.c_str());
	return f.good();
}

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

#endif /* SOURCE_CORE_UTILITY_UTILITYSTRING_H_ */
