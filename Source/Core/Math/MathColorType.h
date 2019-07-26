/*
 * =====================================================================================
 *
 *       Filename:  MathColorType.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_COLOR_TYPE_H
#define SOURCE_CORE_MATH_COLOR_TYPE_H

#include <cstdint>

namespace Math
{
	struct RGBA
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	};

	struct BGRA
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};

	struct ARGB
	{
		uint8_t alpha;
		uint8_t red;
		uint8_t green;
		uint8_t blue;
	};

	struct ABGR
	{
		uint8_t alpha;
		uint8_t blue;
		uint8_t green;
		uint8_t red;
	};

	template<typename C, typename T>
	static inline void SetColor(C& component, T red, T green, T blue, T alpha)
	{
		component.red = static_cast<uint8_t>(red);
		component.green = static_cast<uint8_t>(green);
		component.blue = static_cast<uint8_t>(blue);
		component.alpha = static_cast<uint8_t>(alpha);
	}

	template<typename C>
	static inline void SetColor(C& component, float red, float green, float blue, float alpha)
	{
		component.red = static_cast<uint8_t>(red * 255);
		component.green = static_cast<uint8_t>(green * 255);
		component.blue = static_cast<uint8_t>(blue * 255);
		component.alpha = static_cast<uint8_t>(alpha * 255);
	}

}

#endif
