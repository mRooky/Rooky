/*
 * RenderVector.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVECTOR_HPP_
#define SOURCE_CORE_RENDER_RENDERVECTOR_HPP_

#include <cstdint>

namespace Render
{

template<typename T>
class Vector2_t
{
public:
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
};

typedef Vector2_t<float> Offset2Df;
typedef Vector2_t<int32_t> Point2, Offset2Di;

template<typename T>
class Vector3_t
{
public:
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
};

template<typename T>
class Vector4_t
{
public:
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
	T w = static_cast<T>(0);
};

}

#endif /* SOURCE_CORE_RENDER_RENDERVECTOR_HPP_ */
