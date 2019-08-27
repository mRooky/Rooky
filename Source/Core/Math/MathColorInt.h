#ifndef SOURCE_CORE_MATH_COLOR_INT_H
#define SOURCE_CORE_MATH_COLOR_INT_H

#include "MathColorDefine.h"
#include <string>

namespace Math
{
	class ColorI
	{
	public:
		ColorI(void)
		{}

		~ColorI(void)
		{}

	public:
		explicit ColorI(uint32_t value):
			color(value)
		{}

		inline ColorI(int r, int g, int b, int a)
		{
			argb.red = static_cast<uint8_t>(r);
			argb.green = static_cast<uint8_t>(g);
			argb.blue = static_cast<uint8_t>(b);
			argb.alpha = static_cast<uint8_t>(a);
		}

		inline ColorI(float r, float g, float b, float a)
		{
			SetARGB(r, g, b, a);
		}

		public:
		inline void SetARGB(float r, float g, float b, float a)
		{
			SetComp(argb, r, g, b, a);
		}

		inline void SetRGBA(float r, float g, float b, float a)
		{
			SetComp(rgba, r, g, b, a);
		}

		inline void SetBGRA(float r, float g, float b, float a)
		{
			SetComp(bgra, r, g, b, a);
		}

		inline void SetABGR(float r, float g, float b, float a)
		{
			SetComp(abgr, r, g, b, a);
		}

	public:
		inline operator uint32_t(void) const
		{
			return color;
		}

		inline ColorI& operator=(uint32_t color)
		{
			this->color = color;
			return *this;
		}

	public:
		union
		{
			union
			{
				ARGB argb;
				RGBA rgba;
				BGRA bgra;
				ABGR abgr;
			};
			uint32_t color = 0;
		};
	};
}

#endif
