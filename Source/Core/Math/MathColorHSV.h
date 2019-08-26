/*
 * =====================================================================================
 *
 *       Filename:  MathColorHSV.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_COLOR_HSV_H
#define SOURCE_CORE_MATH_COLOR_HSV_H

namespace Math
{
	class ColorRGB;
	class ColorHSV
	{
	public:
		ColorHSV(void) :
			h(0.0f), s(0.0f), v(0.0f)
		{
		}

		ColorHSV(const ColorHSV& hsv)
		{
			h = hsv.h;
			s = hsv.s;
			v = hsv.v;
		}

		explicit ColorHSV(const ColorRGB& rgb)
		{
			SetRGB(rgb);
		}

	public:
		~ColorHSV(void) = default;

	public:
		inline ColorHSV& operator=(const ColorHSV& hsv)
		{
			if (this != &hsv)
			{
				h = hsv.h;
				s = hsv.s;
				v = hsv.v;
			}
			return *this;
		}

		inline ColorHSV& operator=(const ColorRGB& rgb)
		{
			SetRGB(rgb);
			return *this;
		}

	public:
		void SetRGB(const ColorRGB& rgb);

	public:
		union
		{
			struct
			{
				float hue;			//[0,360]
				float saturation;	//[0,1]
				float value;		//[0,1]
			};
			struct { float h, s, v; };
		};
	};


}

#endif
