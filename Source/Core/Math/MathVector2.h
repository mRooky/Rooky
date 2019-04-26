/*
 * Vector2.h
 *
 *  Created on: Apr 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHVECTOR2_H_
#define SOURCE_CORE_MATH_MATHVECTOR2_H_

#include <cmath>

namespace Math
{

template<typename T>
class Vector2_t
{
public:
	Vector2_t(void) = default;

public:
	template<typename O>
	Vector2_t(O x, O y) { Set(x, y); }

public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }

public:
	template<typename O>
	void Set(O x, O y)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(t);
	}

public:
	union
	{
		struct{	T r; T g; };
		struct{	T s; T t; };
		struct
		{
			T x = static_cast<T>(0);
			T y = static_cast<T>(0);
		};
	};

};

typedef Vector2_t<float> Offset2Df, Vector2f;
typedef Vector2_t<int32_t> Point2, Offset2Di, Vector2i;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHVECTOR2_H_ */
