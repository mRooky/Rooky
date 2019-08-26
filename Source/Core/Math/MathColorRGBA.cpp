/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSV.cpp
 *
 * =====================================================================================
 */
#include "MathColorRGBA.h"
#include "MathColorHSVA.h"
#include <fmt/format.h>

namespace Math
{
	ColorRGBA::ColorRGBA(uint32_t color)
	{
		ColorI component(color);
		const auto& argb = component.argb;
		rgb.SetColor(argb.red, argb.green, argb.blue);
		alpha = argb.alpha / 255.0f;
	}

	ColorRGBA::ColorRGBA(const ColorRGBA& rbga)
	{
		if (this != &rbga)
		{
			rgb = rbga.rgb;
			alpha = rbga.alpha;
		}
	}

	ColorRGBA::ColorRGBA(const ColorHSVA& hsva)
	{
		rgb.SetHSV(hsva.hsv);
		alpha = hsva.alpha;
	}

	ColorRGBA& ColorRGBA::operator=(const ColorHSVA& hsva)
	{
		rgb.SetHSV(hsva.hsv);
		alpha = hsva.alpha;
		return *this;
	}

	std::string ColorRGBA::ToString(void) const
	{
		return fmt::format("[{0},{1},{2},{3}]", rgb.r, rgb.g, rgb.b, alpha);
	}
}

