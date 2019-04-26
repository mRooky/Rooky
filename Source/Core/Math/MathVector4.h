/*
 * MathVector4.h
 *
 *  Created on: Apr 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHVECTOR4_H_
#define SOURCE_CORE_MATH_MATHVECTOR4_H_

#include <cmath>

namespace Math
{

template<typename T>
class Vector4_t
{
public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }

public:
	union
	{
		struct{	T r; T g; T b; T a; };
		struct{	T s; T t; T p; T q; };
		struct
		{
			T x = static_cast<T>(0);
			T y = static_cast<T>(0);
			T z = static_cast<T>(0);
			T w = static_cast<T>(0);
		};
	};
};

typedef Vector4_t<float> Vector4f, ColorValue;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHVECTOR4_H_ */
