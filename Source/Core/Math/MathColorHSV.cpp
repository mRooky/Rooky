/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSV.cpp
 *
 * =====================================================================================
 */
#include "MathColorHSV.h"
#include "MathColorRGB.h"
#include "MathMax.h"
#include "MathMin.h"

namespace Math
{
	void ColorHSV::SetRGB(const ColorRGB& rgb)
	{
		float min = Min(rgb.r, Min(rgb.g, rgb.b));
		float max = Max(rgb.r, Max(rgb.g, rgb.b));
		float delta = max - min;

		v = max;
		if (max != 0.0f)
		{
			s = delta / max;
		}
		else
		{
			s = 0.0f;
			h = 0.0f;
			return;
		}

		if (delta == 0.0f)
		{
			h = 0.0f;
			return;
		}

		if (rgb.r == max)
		{
			if (rgb.g >= rgb.b)
			{
				h = (rgb.g - rgb.b) / delta;
			}
			else
			{
				h = (rgb.g - rgb.b) / delta + 6.0f;
			}
		}
		else if (rgb.g == max)
		{
			h = 2.0f + (rgb.b - rgb.r) / delta;
		}
		else
		{
			h = 4.0f + (rgb.r - rgb.g) / delta;
		}

		h *= 60.0f;

		if (h < 0.0f)
		{
			h += 360.0f;
		}
	}
}

