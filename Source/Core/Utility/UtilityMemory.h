/*
 * UtilityMemory.h
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYMEMORY_H_
#define SOURCE_CORE_UTILITY_UTILITYMEMORY_H_

#include <cstring>

namespace Utility
{

template<typename T>
static inline size_t Memcpy(void* dest, const T& value, size_t count = 1)
{
	size_t size = sizeof(T) * count;
	std::memcpy(dest, &value, size);
	return size;
}

}

#endif /* SOURCE_CORE_UTILITY_UTILITYMEMORY_H_ */
