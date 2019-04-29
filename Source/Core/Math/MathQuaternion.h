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

class Quaternion : public Vector4_t<float>
{
public:
	Quaternion(void);
	~Quaternion(void);
};

} /* namespace Math */

#endif /* SOURCE_CORE_MATH_MATHQUATERNION_H_ */
