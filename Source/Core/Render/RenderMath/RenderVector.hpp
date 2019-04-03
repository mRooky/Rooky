/*
 * RenderVector.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVECTOR_HPP_
#define SOURCE_CORE_RENDER_RENDERVECTOR_HPP_

#include <cstdint>
#include <cstddef>
#include <cmath>

namespace Render
{

template<typename T>
class Vector2_t
{
public:
	inline T& operator[](size_t index) { return *(&x + index); }
	inline const T& operator[](size_t index) const { return *(&x + index); }

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
typedef Vector2_t<int32_t> Point2, Offset2Di;

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
template<typename V>
inline Vector3_t operator+(V value)
{
	return Vector3_t(x + value, y + value, z + value);
}

template<typename V>
inline Vector3_t operator-(V value)
{
	return Vector3_t(x - value, y - value, z - value);
}

template<typename V>
inline Vector3_t operator*(V value)
{
	return Vector3_t(x * value, y * value, z * value);
}

template<typename V>
inline Vector3_t operator/(V value)
{
	return Vector3_t(x / value, y / value, z / value);
}

public:
inline Vector3_t operator+(const Vector3_t& other)
{
	return Vector3_t(x + other.x, y + other.y, z + other.z);
}

inline Vector3_t operator-(const Vector3_t& other)
{
	return Vector3_t(x - other.x, y - other.y, z - other.z);
}

inline Vector3_t operator*(const Vector3_t& other)
{
	return Vector3_t(x * other.x, y * other.y, z * other.z);
}

inline Vector3_t operator/(const Vector3_t& other)
{
	return Vector3_t(x / other.x, y / other.y, z / other.z);
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

typedef Vector3_t<float> Vector3f;

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

typedef Vector4_t<float> Vector4f;

}

#endif /* SOURCE_CORE_RENDER_RENDERVECTOR_HPP_ */
