/*
 * RenderState.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERSTATEENUM_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERSTATEENUM_H_

#include <cstdint>

namespace GHI
{

	enum class BlendFactor : uint32_t
	{
		ZERO,
		ONE,
		SRC_COLOR,
		ONE_MINUS_SRC_COLOR,
		DST_COLOR,
		ONE_MINUS_DST_COLOR,
		SRC_ALPHA,
		ONE_MINUS_SRC_ALPHA,
		DST_ALPHA,
		ONE_MINUS_DST_ALPHA,
		CONSTANT_ALPHA,
		ONE_MINUS_CONSTANT_ALPHA,
		SRC_ALPHA_SATURATE
	};

	enum class BlendOperation
	{
	    ADD = 0,
	    SUBTRACT = 1,
	    REVERSE_SUBTRACT = 2,
	    MIN = 3,
	    MAX = 4,
	};

	enum class DepthFunction : uint32_t
	{
		NEVER,
		LESS,
		EQUAL,
		LEQUAL,
		GREATER,
		NOTEQUAL,
		GEQUAL,
		ALWAYS
	};

	enum class CullFaceSide : uint32_t
	{
		NONE,
		BACK,
		FRONT,
		FRONT_AND_BACK
	};

	enum class FrontFace : uint32_t
	{
		CW,
		CCW
	};

	enum class StencilFunction : uint32_t
	{
		NEVER,
		ALWAYS,
		LESS,
		LEQUAL,
		EQUAL,
		GREATER,
		GEQUAL,
		NOTEQUAL
	};

	enum class StencilOperation : uint32_t
	{
		KEEP,
		ZERO,
		REPLACE,
		INCR,
		DECR,
		INVERT,
		INCR_WRAP,
		DECR_WRAP
	};

	enum class VertexInputRate : uint32_t
	{
	    VERTEX = 0,
	    INSTANCE = 1,
		UNKNOWN = ~0U
	};

	enum class PrimitiveTopology : uint32_t
	{
		POINT_LIST = 0,
		LINE_LIST = 1,
		LINE_STRIP = 2,
		TRIANGLE_LIST = 3,
		TRIANGLE_STRIP = 4,
		TRIANGLE_FAN = 5,
		LINE_LIST_WITH_ADJACENCY = 6,
		LINE_STRIP_WITH_ADJACENCY = 7,
		TRIANGLE_LIST_WITH_ADJACENCY = 8,
		TRIANGLE_STRIP_WITH_ADJACENCY = 9,
		PATCH_LIST = 10
	};

	enum class PolygonMode : uint32_t
	{
		FILL,
		LINE,
		POINT,
		UNKNOWN = ~0U
	};

	enum class CompareOperation : uint32_t
	{
	    NEVER = 0,
	    LESS = 1,
	    EQUAL = 2,
	    LESS_OR_EQUAL = 3,
	    GREATER = 4,
	    NOT_EQUAL = 5,
	    GREATER_OR_EQUAL = 6,
	    ALWAYS = 7
	};
}

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERSTATEENUM_H_ */
