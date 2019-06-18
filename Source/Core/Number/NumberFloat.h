/*
 * RenderFloat.hpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERMATH_RENDERFLOAT_HPP_
#define SOURCE_CORE_GHI_RENDERMATH_RENDERFLOAT_HPP_

#include "NumberTypes.h"

namespace Number
{

class Float
{
	friend class Half;
public:
	Float(float value = 0.0f) : m_floatValue(value){}
	Float(const Float& other) : m_floatValue(other.m_floatValue){}
	~Float(void) = default;

public:
	inline operator float (void) const { return m_floatValue; }

public:
	inline bool operator==(const float& value) const
	{
		return CloseEnough(m_floatValue, value);
	}

	inline bool operator==(const Float& other) const
	{
		return CloseEnough(m_floatValue, other.m_floatValue);
	}

public:
	inline const Float32Components& GetComponets(void) const { return m_components; }

public:
	inline Float& operator=(float value) { m_floatValue = value; return *this; }
	inline Float& operator=(const Float& other) { m_floatValue = other.m_floatValue; return *this; }

private:
	union
	{
		Float32Components m_components;
		float m_floatValue = 0.0f;
	};

};

}

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERFLOAT_HPP_ */
