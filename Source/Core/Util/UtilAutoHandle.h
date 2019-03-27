/*
 * AutoHandle.h
 *
 *  Created on: Mar 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTIL_UTILAUTOHANDLE_H_
#define SOURCE_CORE_UTIL_UTILAUTOHANDLE_H_

namespace Util
{

template<class T>
class AutoHandle
{
public:
	AutoHandle(T* ptr = nullptr);
	~AutoHandle(void);

private:
	T* m_ptr = nullptr;
};

// Implement
template<class T>
inline AutoHandle<T>::AutoHandle(T* ptr):
	m_ptr(ptr)
{
}

template<class T>
inline AutoHandle<T>::~AutoHandle(void)
{
}

} /* namespace Util */

#endif /* SOURCE_CORE_UTIL_UTILAUTOHANDLE_H_ */
