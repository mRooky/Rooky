/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSV.cpp
 *
 * =====================================================================================
 */
#include "MathColorHSVA.h"
#include "MathColorRGBA.h"
#include <fmt/format.h>

namespace Math
{
	ColorHSVA::ColorHSVA(const ColorHSVA& hsva)
	{
		if (this != &hsva)
		{
			hsv = hsva.hsv;
			alpha = hsva.alpha;
		}
	}

	ColorHSVA::ColorHSVA(const ColorRGBA& rgba)
	{
		hsv.SetRGB(rgba.rgb);
		alpha = rgba.alpha;
	}

	ColorHSVA& ColorHSVA::operator=(const ColorRGBA& rgba)
	{
		hsv.SetRGB(rgba.rgb);
		alpha = rgba.alpha;
		return *this;
	}

	std::string ColorHSVA::ToString(void) const
	{
		return fmt::format("[{0},{1},{2},{3}]", hsv.h, hsv.s, hsv.v, alpha);
	}
}

