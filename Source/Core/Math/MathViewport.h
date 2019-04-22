/*
 * RenderViewport.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_
#define SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_

#include "MathRect.hpp"

namespace Math
{

class Viewport
{
public:
	Viewport(void) = default;
	~Viewport(void) = default;

public:
	inline Viewport(const Rect2Di& rect)
	{
		SetOffset(rect.offset);
		SetExtent(rect.extent);
	}
	inline Viewport(const Extent2Di& extent) { SetExtent(extent); }
	inline Viewport(const Extent3Di& extent) { SetExtent(extent.width, extent.height); }

public:
	inline void SetOffset(const Vector2i& offset)
	{
		this->x = static_cast<float>(offset.x);
		this->y = static_cast<float>(offset.y);
	}

	inline void SetOffset(int32_t x, int32_t y)
	{
		this->x = static_cast<float>(x);
		this->y = static_cast<float>(y);
	}

public:
	inline void SetExtent(const Extent2Di& extent)
	{
		this->width = static_cast<float>(extent.width);
		this->height = static_cast<float>(extent.height);
	}

	inline void SetExtent(const Extent3Di& extent)
	{
		this->width = static_cast<float>(extent.width);
		this->height = static_cast<float>(extent.height);
	}

	inline void SetExtent(int32_t width, int32_t height)
	{
		this->width = static_cast<float>(width);
		this->height = static_cast<float>(height);
	}

public:
	inline Vector2i GetOffset(void) const { return Vector2i(x, y); }
	inline Extent2Di GetExtent(void) const { return Extent2Di(width, height); }

public:
    float x = 0.0f;
    float y = 0.0f;
    float width = 0.0f;
    float height = 0.0f;
    float minDepth = 0.0f;
    float maxDepth = 1.0f;
};

}

#endif /* SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_ */
