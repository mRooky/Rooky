/*
 * UtilFastCast.hpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYFASTCAST_HPP_
#define SOURCE_CORE_UTILITY_UTILITYFASTCAST_HPP_

namespace Utility
{

template<class O, typename I>
static inline O* FastCast(I* in)
{
   if(in != nullptr)
   {
      O* out = static_cast<O*>(in);
      return out;
   }
   return nullptr;
}

template<>
static inline void* FastCast<void>(void* in)
{
   return in;
}

}

#endif /* SOURCE_CORE_UTILITY_UTILITYFASTCAST_HPP_ */
