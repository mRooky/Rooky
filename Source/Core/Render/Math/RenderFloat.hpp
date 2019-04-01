/*
 * RenderFloat.hpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_MATH_RENDERFLOAT_HPP_
#define SOURCE_CORE_RENDER_MATH_RENDERFLOAT_HPP_

#include <limits>
#include <cmath>

namespace Render
{
	static inline bool CloseEnough(const float& v1, const float& v2)
	{
		return std::abs(v1 - v2) < std::numeric_limits<float>::epsilon();
	}
}

#endif /* SOURCE_CORE_RENDER_MATH_RENDERFLOAT_HPP_ */
