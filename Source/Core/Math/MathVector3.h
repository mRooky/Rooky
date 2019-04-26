/*
 * MathVector3.h
 *
 *  Created on: Apr 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHVECTOR3_H_
#define SOURCE_CORE_MATH_MATHVECTOR3_H_

#include <cmath>

namespace Math
{

template<typename T>
class Vector3_t
{
public:
	Vector3_t(T X = 0, T Y = 0, T Z = 0) : x(X), y(Y), z(Z) {}

public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }
	inline T Length(void) const { return std::sqrt(x * x + y * y + z * z); }

public:
	union
	{
		struct{	T r; T g; T b; };
		struct{	T s; T t; T p; };
		struct
		{
			T x = static_cast<T>(0);
			T y = static_cast<T>(0);
			T z = static_cast<T>(0);
		};
	};

};

typedef Vector3_t<float> Vector3f;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHVECTOR3_H_ */
