#ifndef SOURCE_CORE_MATH_COLOR_DEFINE_H
#define SOURCE_CORE_MATH_COLOR_DEFINE_H

#include <cstdint>

namespace Math
{
	struct RGBA
	{
		uint8_t alpha;
		uint8_t blue;
		uint8_t green;
		uint8_t red;
	};

	struct BGRA
	{
		uint8_t alpha;
		uint8_t red;
		uint8_t green;
		uint8_t blue;
	};

	struct ARGB
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};

	struct ABGR
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	};

	template<typename T>
	static inline void SetComp(T& comp, float r, float g, float b, float a)
	{
		comp.red = static_cast<uint8_t>(r * 255.0f);
		comp.green = static_cast<uint8_t>(g * 255.0f);
		comp.blue = static_cast<uint8_t>(b * 255.0f);
		comp.alpha = static_cast<uint8_t>(a * 255.0f);
	}

}

#endif

