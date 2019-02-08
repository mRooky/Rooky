/*
 * MathVector3.hpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHVECTOR3_HPP_
#define SOURCE_CORE_MATH_MATHVECTOR3_HPP_

#include <cstdint>
#include <cstddef>

namespace Math
{

template<typename T>
class Vector3
{
public:
	Vector3(void) = default;
	Vector3(T X, T Y, T Z): x(X), y(Y), z(Z){}
	Vector3(const Vector3& other): x(other.x), y(other.y), z(other.z){}
	~Vector3(void) = default;

public:
	inline operator T* (void) { return &x; }
	inline operator const T* (void) const { return &x; }

public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }

public:
	inline Vector3& operator =(const Vector3& other);

public:
	T x = static_cast<T>(0);
	T y = static_cast<T>(0);
	T z = static_cast<T>(0);
};

// inline implement

template<typename T>
inline Vector3<T>& Vector3<T>::operator = (const Vector3<T>& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

}

#endif /* SOURCE_CORE_MATH_MATHVECTOR3_HPP_ */
