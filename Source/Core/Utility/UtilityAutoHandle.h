/*
 * AutoHandle.h
 *
 *  Created on: Mar 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYAUTOHANDLE_H_
#define SOURCE_CORE_UTILITY_UTILITYAUTOHANDLE_H_

namespace Utility
{

template<class T>
class AutoHandle
{
public:
	AutoHandle(T* ptr = nullptr) : m_ptr(ptr) {}
	~AutoHandle(void) {}

private:
	T* m_ptr = nullptr;
};

} /* namespace Util */

#endif /* SOURCE_CORE_UTILITY_UTILITYAUTOHANDLE_H_ */
