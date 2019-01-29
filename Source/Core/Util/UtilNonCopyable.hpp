/*
 * UtilNoncopyable.hpp
 *
 *  Created on: Jan 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTIL_UTILNONCOPYABLE_HPP_
#define SOURCE_CORE_UTIL_UTILNONCOPYABLE_HPP_

namespace Util
{

class NonCopyable
{
private:
	NonCopyable(const NonCopyable&) = delete;
	const NonCopyable& operator=(const NonCopyable&) = delete;
};

}

#endif /* SOURCE_CORE_UTIL_UTILNONCOPYABLE_HPP_ */
