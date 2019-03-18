/*
 * RenderViewport.hpp
 *
 *  Created on: Mar 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_
#define SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_

#include "RenderExtent.hpp"

namespace Render
{

class Viewport
{
public:
	Viewport(void) = default;
	~Viewport(void) = default;

public:
	inline Viewport(const Extent2D& extent) { Set(extent.width, extent.height); }
	inline Viewport(const Extent3D& extent) { Set(extent.width, extent.height); }

public:
	inline void Set(int32_t width, int32_t height)
	{
		this->width = static_cast<float>(width);
		this->height = static_cast<float>(height);
	}

public:
    float    x = 0.0f;
    float    y = 0.0f;
    float    width = 0.0f;
    float    height = 0.0f;
    float    minDepth = 0.0f;
    float    maxDepth = 1.0f;
};

}

#endif /* SOURCE_CORE_RENDER_RENDERVIEWPORT_HPP_ */
