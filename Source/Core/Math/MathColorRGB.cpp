/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSV.cpp
 *
 * =====================================================================================
 */
#include "MathColorRGB.h"
#include "MathColorHSV.h"
#include "MathMax.h"
#include "MathMin.h"

namespace Math
{
	void ColorRGB::SetHSV(const ColorHSV& hsv)
	{
		if (hsv.s == 0)
		{
			r = g = b = hsv.v;
			return;
		}

		ColorHSV temp(hsv);
		temp.h /= 60;
		int i = static_cast<int>(temp.h);
		float f = temp.h - i;
		float p = temp.v * (1 - temp.s);
		float q = temp.v * (1 - temp.s * f);
		float t = temp.v * (1 - temp.s * (1 - f));
		switch (i)
		{
		case 0:
			r = temp.v;
			g = t;
			b = p;
			break;
		case 1:
			r = q;
			g = temp.v;
			b = p;
			break;
		case 2:
			r = p;
			g = temp.v;
			b = t;
			break;
		case 3:
			r = p;
			g = q;
			b = temp.v;
			break;
		case 4:
			r = t;
			g = p;
			b = temp.v;
			break;
		default:
			r = temp.v;
			g = p;
			b = q;
			break;
		}
	}
}
