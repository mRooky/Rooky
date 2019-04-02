/*
 * RenderMatrix.hpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERMATH_RENDERMATRIX_HPP_
#define SOURCE_CORE_RENDER_RENDERMATH_RENDERMATRIX_HPP_

#include "RenderVector.hpp"
#include <cstring>

namespace Render
{

template<typename T>
class Matrix_t
{
public:
	Matrix_t(void) { Identity(); }
	~Matrix_t(void) = default;

public:
	inline void Identity(void)
	{
		std::memset(data, 0, sizeof(data));
		array[0][0] = static_cast<T>(0);
		array[1][1] = static_cast<T>(0);
		array[2][2] = static_cast<T>(0);
		array[3][3] = static_cast<T>(0);
	}

public:
	inline Vector4_t<T>& operator[](size_t index) { return array[index]; }
	inline const Vector4_t<T>& operator[](size_t index) const { return array[index]; }

public:
	union
	{
		T data[16];
		Vector4_t<T> array[4];
	};
};

typedef Matrix_t<float> Matrix;
static_assert(sizeof(Matrix) == sizeof(float) * 16, "Matrix Size 16 * float");

}

#endif /* SOURCE_CORE_RENDER_RENDERMATH_RENDERMATRIX_HPP_ */
