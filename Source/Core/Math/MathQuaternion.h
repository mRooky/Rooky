/*
 * MathQuaternion.h
 *
 *  Created on: Apr 29, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_MATHQUATERNION_H_
#define SOURCE_CORE_MATH_MATHQUATERNION_H_

#include "MathVector4.h"

namespace Math
{

template<typename T>
class Quaternion_t : public Vector4_t<T>
{
public:
	Quaternion_t(void);
	~Quaternion_t(void);
};

typedef Quaternion_t<float> Quaternion;

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHQUATERNION_H_ */
