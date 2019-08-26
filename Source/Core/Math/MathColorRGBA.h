/*
 * =====================================================================================
 *
 *       Filename:  MathColorRGBA.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_MATH_CORE_COLOR_RGBA_H
#define SOURCE_MATH_CORE_COLOR_RGBA_H

#include "MathColorInt.h"
#include "MathColorRGB.h"
#include <string>

namespace Math
{
	class ColorHSVA;
	class ColorRGBA
	{
	public:
		ColorRGBA(void) = default;
		~ColorRGBA(void) = default;

	public:
		ColorRGBA(const ColorRGBA& rbga);
		explicit ColorRGBA(uint32_t color);
		explicit ColorRGBA(const ColorHSVA& hsva);

	public:
		ColorRGBA& operator = (const ColorHSVA& hsva);
		std::string ToString(void) const;

	public:
		inline operator uint32_t(void) const
		{
			ColorI component;
			component.SetARGB(rgb.r, rgb.g, rgb.b, alpha);
			return component.color;
		}

		inline ColorRGBA& operator=(uint32_t color)
		{
			ColorI component(color);
			const auto& argb = component.argb;
			rgb.SetColor(argb.red, argb.green, argb.blue);
			alpha = argb.alpha / 255.0f;
			return *this;
		}

	public:
		ColorRGB rgb;
		float alpha = 1.0f;		//[0,1]
	};

}

#endif
