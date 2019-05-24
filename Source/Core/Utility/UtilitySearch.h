/*
 * UtilSearch.h
 *
 *  Created on: Mar 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYSEARCH_H_
#define SOURCE_CORE_UTILITY_UTILITYSEARCH_H_

#include <array>
#include <vector>
#include <algorithm>

namespace Utility
{

template<typename T>
static inline auto Find(const std::vector<T>& container, const T& value)
{
	return std::find(container.begin(), container.end(), value);
}

template<typename T, size_t N>
static inline auto Find(const std::array<T, N>& container, const T& value)
{
	return std::find(container.begin(), container.end(), value);
}

template<typename T, typename V>
static inline auto Find(const std::vector<T>& container, const V& value)
{
	return std::find(container.begin(), container.end(), value);
}


}

#endif /* SOURCE_CORE_UTILITY_UTILITYSEARCH_H_ */
