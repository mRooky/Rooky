/*
 * UtilRelease.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYRELEASE_H_
#define SOURCE_CORE_UTILITY_UTILITYRELEASE_H_

#include <vector>

namespace Utility
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

#endif /* SOURCE_CORE_UTILITY_UTILITYRELEASE_H_ */
