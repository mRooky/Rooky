/*
 * UtilRelease.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTIL_UTILRELEASE_H_
#define SOURCE_CORE_UTIL_UTILRELEASE_H_

#include <vector>

namespace Util
{

template<typename T>
static inline void Release(std::vector<T*>& list)
{
	for (auto item : list)
	{
		delete item;
	}
	list.clear();
}

}

#endif /* SOURCE_CORE_UTIL_UTILRELEASE_H_ */
