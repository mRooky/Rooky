/*
 * =====================================================================================
 *
 *       Filename:  MathColorRGB.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_COLOR_RGB_H
#define SOURCE_CORE_MATH_COLOR_RGB_H

#include <cstdint>

namespace Math
{
	class ColorHSV;
	class ColorRGB
	{
	public:
		ColorRGB(float r = 0.0f, float g = 0.0f, float b = 0.0f) :
			red(r), green(g), blue(b)
		{
		}

		ColorRGB(const ColorRGB& rgb)
		{
			r = rgb.r;
			g = rgb.g;
			b = rgb.b;
		}

		ColorRGB(const ColorHSV& hsv)
		{
			SetHSV(hsv);
		}

	public:
		~ColorRGB(void) = default;

	public:
		void SetColor(uint8_t r, uint8_t g, uint8_t b)
		{
			red = r / 255.0f;
			green = g / 255.0f;
			blue = b / 255.0f;
		}

	public:
		inline ColorRGB& operator=(const ColorRGB& rgb)
		{
			if (this != &rgb)
			{
				r = rgb.r;
				g = rgb.g;
				b = rgb.b;
			}
			return *this;
		}

		inline ColorRGB& operator=(const ColorHSV& hsv)
		{
			SetHSV(hsv);
			return *this;
		}

		template<typename T>
		inline ColorRGB operator*(const T& value)
		{
			return ColorRGB(r * value, g * value, b * value);
		}

	public:
		void SetHSV(const ColorHSV& hsv);

	public:
		union
		{
			struct
			{
				float red;		//[0,1]
				float green;	//[0,1]
				float blue;		//[0,1]
			};
			struct { float r, g, b; };
		};
	};

}

#endif
