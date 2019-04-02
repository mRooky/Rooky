/*
 * RenderHalf.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "RenderHalf.h"

namespace Render
{

float Half::GetFloat(void) const
{
	// From UE
	Float float32;
	float32.m_components.sign = m_components.sign;
	if (m_components.exponent == 0)
	{
		uint32_t mantissa = m_components.mantissa;
		if (mantissa == 0)
		{
			float32.m_components.exponent = 0;
			float32.m_components.mantissa = 0;
		}
		else
		{
			uint32_t shift = 10 - static_cast<uint32_t>(std::trunc(std::log2(mantissa)));
			float32.m_components.exponent = 127 - (15 - 1) - shift;
			float32.m_components.mantissa = mantissa << (shift + 23 - 10);
		}
	}
	else if (m_components.exponent == 31)
	{
		float32.m_components.exponent = 142;
		float32.m_components.mantissa = 8380416;
	}
	else
	{
		float32.m_components.exponent = static_cast<int32_t>(m_components.exponent) - 15 + 127;
		float32.m_components.mantissa = static_cast<uint32_t>(m_components.mantissa) << 13;
	}
	return float32.m_floatValue;
}

void Half::SetFloat(float value)
{
	// From UE
	Float float32(value);
	m_components.sign = float32.m_components.sign;
	if (float32.m_components.exponent <= 112)
	{
		m_components.exponent = 0;
		m_components.mantissa = 0;
		const int32_t exp = float32.m_components.exponent - 127 + 15;
		if ((14 - exp) <= 24)
		{
			uint32_t mantissa = float32.m_components.mantissa | 0x800000;
			m_components.mantissa = mantissa >> (14 - exp);
			if (mantissa >> (13 - exp) & 1)
			{
				++m_encoded;
			}
		}
	}
	else if (float32.m_components.exponent >= 143)
	{
		m_components.exponent = 30;
		m_components.mantissa = 1023;
	}
	else
	{
		m_components.exponent = static_cast<int32_t>(float32.m_components.exponent) - 127 + 15;
		m_components.mantissa = static_cast<uint16_t>(float32.m_components.mantissa >> 13);
	}
}

}

