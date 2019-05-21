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
	Vector3_t(void) = default;
	explicit Vector3_t(T x, T y, T z) { Set(x, y, z); }
	~Vector3_t(void) = default;

public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }
	inline T Length(void) const { return std::sqrt(x * x + y * y + z * z); }

public:
	inline void Set(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

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

// Non-Member Static Functions
template<typename T>
static inline Vector3_t<T> operator+(const Vector3_t<T>& vector, T value)
{
	return Vector3_t<T>(vector.x + value, vector.y + value, vector.z + value);
}

template<typename T>
static inline Vector3_t<T> operator-(const Vector3_t<T>& vector, T value)
{
	return Vector3_t<T>(vector.x - value, vector.y - value, vector.z - value);
}

template<typename T>
static inline Vector3_t<T> operator*(const Vector3_t<T>& vector, T value)
{
	return Vector3_t<T>(vector.x * value, vector.y * value, vector.z * value);
}

template<typename T>
static inline Vector3_t<T> operator/(const Vector3_t<T>& vector, T value)
{
	return Vector3_t<T>(vector.x / value, vector.y / value, vector.z / value);
}

template<typename T>
static inline Vector3_t<T> operator+(const Vector3_t<T>& vector, const Vector3_t<T>& other)
{
	return Vector3_t<T>(vector.x + other.x, vector.y + other.y, vector.z + other.z);
}

template<typename T>
static inline Vector3_t<T> operator-(const Vector3_t<T>& vector, const Vector3_t<T>& other)
{
	return Vector3_t<T>(vector.x - other.x, vector.y - other.y, vector.z - other.z);
}

template<typename T>
static inline Vector3_t<T> operator*(const Vector3_t<T>& vector, const Vector3_t<T>& other)
{
	return Vector3_t<T>(vector.x * other.x, vector.y * other.y, vector.z * other.z);
}

template<typename T>
static inline Vector3_t<T> operator/(const Vector3_t<T>& vector, const Vector3_t<T>& other)
{
	return Vector3_t<T>(vector.x / other.x, vector.y / other.y, vector.z / other.z);
}

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHVECTOR3_H_ */
