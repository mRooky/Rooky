/*
 * MathVector2.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHVECTOR2_HPP_
#define SOURCE_CORE_MATH_MATHVECTOR2_HPP_

#include <cstddef>
#include <cstdint>

namespace Math
{

template<typename T>
class Vector2
{
public:
	Vector2(void) = default;
	Vector2(T X, T Y): x(X), y(Y) {}
	Vector2(const Vector2& other) : x(other.x), y(other.y) {}
	~Vector2(void) = default;

public:
	inline operator T* (void) { return &x; }
	inline operator const T* (void) const { return &x; }

public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }

public:
	Vector2& operator = (const Vector2& other);

public:
	Vector2 operator + (T value) const;
	Vector2 operator * (T value) const;

public:
	Vector2& operator *= (T value);

public:
	Vector2 operator + (const Vector2& other) const;
	Vector2& operator += (const Vector2& other);

public:
	bool Contain(const T value) const;

public:
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
};

// inline implement

template<typename T>
inline Vector2<T>& Vector2<T>::operator = (const Vector2<T>& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

template<typename T>
inline Vector2<T> Vector2<T>::operator + (const Vector2<T>& other) const
{
	Vector2 vector = {};
	vector.x = x + other.x;
	vector.y = y + other.y;
	return vector;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator += (const Vector2<T>& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

template<typename T>
inline Vector2<T> Vector2<T>::operator + (T value) const
{
	Vector2 vector = {};
	vector.x = x + value;
	vector.y = y + value;
	return vector;
}

template<typename T>
inline Vector2<T> Vector2<T>::operator * (T value) const
{
	Vector2 vector = {};
	vector.x = x * value;
	vector.y = y * value;
	return vector;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator *= (T value)
{
	x *= value;
	y *= value;
	return *this;
}

template<typename T>
inline bool Vector2<T>::Contain(const T value) const
{
	return InRange(value, x, y);
}

}

#endif /* SOURCE_CORE_MATH_MATHVECTOR2_HPP_ */
