/*
 * UtilNoncopyable.hpp
 *
 *  Created on: Jan 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYNONCOPYABLE_HPP_
#define SOURCE_CORE_UTILITY_UTILITYNONCOPYABLE_HPP_

namespace Utility
{

class NonCopy
{
private:
	NonCopy(const NonCopy&) = delete;
	const NonCopy& operator=(const NonCopy&) = delete;
};

}

#endif /* SOURCE_CORE_UTILITY_UTILITYNONCOPYABLE_HPP_ */
