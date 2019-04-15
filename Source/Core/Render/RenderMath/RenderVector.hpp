/*
 * RenderVector.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */


#include "RenderVector.h"

namespace Render
{

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

}
