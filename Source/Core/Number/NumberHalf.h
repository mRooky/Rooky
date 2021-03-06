/*
 * RenderHalf.hpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERMATH_RENDERHALF_H_
#define SOURCE_CORE_GHI_RENDERMATH_RENDERHALF_H_

#include "NumberFloat.h"

namespace Number
{

class Half
{
public:
	Half(float value = 0.0f)
	{
		SetFloat(value);
	}

	Half(const Half& other) :
		m_encoded(other.m_encoded)
	{
	}

	~Half(void) = default;

public:
	float GetFloat(void) const;
	void SetFloat(float value);

public:
	inline operator float (void) const
	{
		return GetFloat();
	}

	inline operator uint16_t (void) const
	{
		return m_encoded;
	}

public:
	inline bool operator==(const Half& other) const
	{
		return m_encoded == other.m_encoded;
	}

public:
	inline Half& operator=(float value)
	{
		SetFloat(value); return *this;
	}

	inline Half& operator=(const Half& other)
	{
		m_encoded = other.m_encoded; return *this;
	}

private:
	union
	{
		uint16_t m_encoded = 0;
		Float16Components m_components;
	};

};

}

#endif /* SOURCE_CORE_GHI_RENDERMATH_RENDERHALF_H_ */
