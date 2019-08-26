/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSVA.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_COLOR_HSVA_H
#define SOURCE_CORE_MATH_COLOR_HSVA_H

#include "MathColorHSV.h"
#include <string>

namespace Math
{
	class ColorRGBA;
	class ColorHSVA
	{
	public:
		ColorHSVA(void) = default;
		~ColorHSVA(void) = default;

	public:
		ColorHSVA(const ColorHSVA& hsva);
		explicit ColorHSVA(const ColorRGBA& rgba);

	public:
		ColorHSVA& operator=(const ColorRGBA& rgba);
		std::string ToString(void) const;

	public:
		ColorHSV hsv;
		float alpha = 1.0f;		//[0,1]
	};

}

#endif
