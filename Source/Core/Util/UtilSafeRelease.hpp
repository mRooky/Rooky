/*
 * UtilSafeRelease.hpp
 *
 *  Created on: Jan 19, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTIL_UTILSAFERELEASE_HPP_
#define SOURCE_CORE_UTIL_UTILSAFERELEASE_HPP_

namespace Util
{

template<class T>
static inline void SafeRelease(T*& ptr)
{
	if(ptr != nullptr)
	{
		ptr->Release();
	}
	ptr = nullptr;
}

template<class T>
static inline void SafeDestroy(T*& ptr)
{
	if(ptr != nullptr)
	{
		ptr->Destroy();
	}
	ptr = nullptr;
}

}

#endif /* SOURCE_CORE_UTIL_UTILSAFERELEASE_HPP_ */
