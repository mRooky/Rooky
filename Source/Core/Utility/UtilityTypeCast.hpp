/*
 * UtilSafeCast.hpp
 *
 *  Created on: Jan 19, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYTYPECAST_HPP_
#define SOURCE_CORE_UTILITY_UTILITYTYPECAST_HPP_

#include <cassert>

namespace Utility
{

template<class O, typename I>
static inline O* StaticCast(I* in)
{
   if(in != nullptr)
   {
      O* out = static_cast<O*>(in);
      return out;
   }
   return nullptr;
}

template<class O, typename I>
static inline O* SafeCast(I* in)
{
   if(in != nullptr)
   {
      O* out = dynamic_cast<O*>(in);
      assert(out != nullptr);
      return out;
   }
   return nullptr;
}

template<>
static inline void* SafeCast<void>(void* in)
{
   return in;
}

}

#endif /* SOURCE_CORE_UTILITY_UTILITYTYPECAST_HPP_ */
