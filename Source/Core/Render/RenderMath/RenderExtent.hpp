/*
 * RenderExtent.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDEREXTENT_HPP_
#define SOURCE_CORE_RENDER_RENDEREXTENT_HPP_

#include <cstdint>

namespace Render
{

template<typename T>
class Extent2_t
{
public:
	Extent2_t(void) = default;
	template<typename O>
	Extent2_t(O width, O height) { Set(width, height); }

public:
	inline T GetArea(void) const
	{
		return width * height;
	}

public:
	template<typename O>
	void Set(O width, O height)
	{
		this->width = static_cast<T>(width);
		this->width = static_cast<T>(height);
	}

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
};

typedef Extent2_t<int32_t> Extent2Di;

template<typename T>
class Extent3_t
{
public:
	inline T GetVolume(void) const
	{
		return width * height * depth;
	}

public:
	T width = static_cast<T>(0);
	T height = static_cast<T>(0);
	T depth = static_cast<T>(0);
};

typedef Extent3_t<int32_t> Extent3Di;

}

#endif /* SOURCE_CORE_RENDER_RENDEREXTENT_HPP_ */
