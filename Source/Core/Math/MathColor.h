/*
 * RenderColor.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATH_RENDERCOLOR_HPP_
#define SOURCE_CORE_MATH_RENDERCOLOR_HPP_

#include <cstdint>

namespace Math
{

struct ColorComponent
{
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
	uint8_t alpha = 255;
};

class Color
{
public:
	Color(void) = default;
	~Color(void) = default;

public:
	Color(uint32_t color)
	{
		Set(color);
	}

	Color(float red, float green, float blue, float alpha = 1.0f)
	{
		Set(red, green, blue, alpha);
	}

	Color(int32_t red, int32_t green, int32_t blue, int32_t alpha = 255)
	{
		Set(red, green, blue, alpha);
	}

public:
	inline void Set(uint32_t color)
	{
		this->color = color;
	}

	inline void Set(float red, float green, float blue, float alpha = 1.0f)
	{
		mComponent.red = static_cast<uint8_t>(red) * 255;
		mComponent.green = static_cast<uint8_t>(green) * 255;
		mComponent.blue = static_cast<uint8_t>(blue) * 255;
		mComponent.alpha = static_cast<uint8_t>(alpha) * 255;
	}

	inline void Set(int32_t red, int32_t green, int32_t blue, int32_t alpha = 255)
	{
		mComponent.red = static_cast<uint8_t>(red);
		mComponent.green = static_cast<uint8_t>(green);
		mComponent.blue = static_cast<uint8_t>(blue);
		mComponent.alpha = static_cast<uint8_t>(alpha);
	}

public:
	inline float GetRed(void) const
	{
		return static_cast<float>(mComponent.red) / 255.0f;
	}

	inline float GetGreen(void) const
	{
		return static_cast<float>(mComponent.green) / 255.0f;
	}

	inline float GetBlue(void) const
	{
		return static_cast<float>(mComponent.blue) / 255.0f;
	}

	inline float GetAlpha(void) const
	{
		return static_cast<float>(mComponent.alpha) / 255.0f;
	}

public:
	inline operator uint32_t(void) const { return color; }

public:
	union
	{
		uint32_t color;
		ColorComponent mComponent = {};
	};
};

}

#endif /* SOURCE_CORE_MATH_RENDERCOLOR_HPP_ */
