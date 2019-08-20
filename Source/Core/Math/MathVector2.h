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
	~Vector2_t(void) = default;

public:
	Vector2_t(T x, T y)
	{
		Set(x, y);
	}

public:
	inline T& operator[](size_t index)
	{
		return *(&x + index);
	}

	inline const T& operator[](size_t index) const
	{
		return *(&x + index);
	}

public:
	inline void Set(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	template<typename O>
	inline void From(O x, O y)
	{
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
	}

public:
	union
	{
		T data[2];
		struct{	T r; T g; };
		struct{	T s; T t; };
		struct
		{
			T x = static_cast<T>(0);
			T y = static_cast<T>(0);
		};
	};

};

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHVECTOR2_H_ */
