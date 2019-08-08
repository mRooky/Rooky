/*
 * RenderColor.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_RENDERCOLOR_HPP_
#define SOURCE_CORE_MATH_RENDERCOLOR_HPP_

#include "MathColorType.h"

namespace Math
{

class ColorI
{
public:
	ColorI(void) = default;
	~ColorI(void) = default;

public:
	ColorI(uint32_t color)
	{
		Set(color);
	}

	template<typename T>
	ColorI(T red, T green, T blue, T alpha = 255)
	{
		SetColor(rgba, red, green, blue, alpha);
	}

	ColorI(float red, float green, float blue, float alpha = 1.0f)
	{
		SetColor(rgba, red, green, blue, alpha);
	}

public:
	inline void Set(uint32_t color)
	{
		this->color = color;
	}

	inline void SetRGBA(float red, float green, float blue, float alpha = 1.0f)
	{
		SetColor(rgba, red, green, blue, alpha);
	}

	inline void SetRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
	{
		SetColor(rgba, red, green, blue, alpha);
	}

public:
	inline float GetRed(void) const
	{
		return static_cast<float>(rgba.red) / 255.0f;
	}

	inline float GetGreen(void) const
	{
		return static_cast<float>(rgba.green) / 255.0f;
	}

	inline float GetBlue(void) const
	{
		return static_cast<float>(rgba.blue) / 255.0f;
	}

	inline float GetAlpha(void) const
	{
		return static_cast<float>(rgba.alpha) / 255.0f;
	}

public:
	inline operator uint32_t(void) const
	{
		return color;
	}

public:
	union
	{
		uint32_t color;
		union
		{
			RGBA rgba;
			BGRA bgra;
			ARGB argb;
			ABGR abgr;
		};
	};
};

}

#endif /* SOURCE_CORE_MATH_RENDERCOLOR_HPP_ */
