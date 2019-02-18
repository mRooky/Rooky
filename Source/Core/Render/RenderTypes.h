/*
 * RenderTypes.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERTYPES_H_
#define SOURCE_CORE_RENDER_RENDERTYPES_H_

#include <cstdint>

namespace Render
{
	enum class ImageType : uint32_t
	{
		IMAGE_TYPE_1D,
		IMAGE_TYPE_2D,
		IMAGE_TYPE_3D,
		IMAGE_TYPE_CUBE,
		IMAGE_TYPE_1D_ARRAY,
		IMAGE_TYPE_2D_ARRAY,
		IMAGE_TYPE_CUBE_ARRAY,
		IMAGE_TYPE_UNKNOWN = ~0u
	};

	enum class IndexType : uint32_t
	{
		INDEX_TYPE_U16,
		INDEX_TYPE_U32,
		INDEX_TYPE_UNKNOWN = ~0u
	};

	enum class BufferUsageFlags : uint32_t
	{
		BUFFER_USAGE_COMMON = 0 << 0,
		BUFFER_USAGE_INDEX = 1 << 0,
		BUFFER_USAGE_VERTEX = 1 << 1,
		BUFFER_USAGE_UNIFORM = 1 << 2,
		BUFFER_USAGE_STORAGE = 1 << 3,
		BUFFER_USAGE_INDIRECT = 1 << 4,
		BUFFER_USAGE_UNIFORM_TEXEL = 1 << 5,
		BUFFER_USAGE_STORAGE_TEXEL = 1 << 6,
		BUFFER_USAGE_UNKNOWN = ~0u
	};

	enum class ImageUsageFlags : uint32_t
	{
		IMAGE_USAGE_COMMON = 0 << 0,
	    IMAGE_USAGE_SAMPLED = 1 << 0,
	    IMAGE_USAGE_STORAGE = 1 << 1,
	    IMAGE_USAGE_COLOR_ATTACHMENT = 1 << 2,
	    IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT = 1 << 3,
	    IMAGE_USAGE_TRANSIENT_ATTACHMENT = 1 << 4,
	    IMAGE_USAGE_INPUT_ATTACHMENT = 1 << 5,
	    IMAGE_USAGE_UNKNOWN = ~0u
	};

	enum class HeapAccess : uint32_t
	{
		HEAP_ACCESS_GPU_ONLY,
		HEAP_ACCESS_CPU_VISIBLE,
		HEAP_ACCESS_UNKNOWN
	};

	enum class Blend : uint32_t
	{
		BLEND_ZERO,
		BLEND_ONE,
		BLEND_SRC_COLOR,
		BLEND_ONE_MINUS_SRC_COLOR,
		BLEND_DST_COLOR,
		BLEND_ONE_MINUS_DST_COLOR,
		BLEND_SRC_ALPHA,
		BLEND_ONE_MINUS_SRC_ALPHA,
		BLEND_DST_ALPHA,
		BLEND_ONE_MINUS_DST_ALPHA,
		BLEND_CONSTANT_ALPHA,
		BLEND_ONE_MINUS_CONSTANT_ALPHA,
		BLEND_SRC_ALPHA_SATURATE
	};

	enum class DepthFunction : uint32_t
	{
		DEPTH_FUNCTION_NEVER,
		DEPTH_FUNCTION_LESS,
		DEPTH_FUNCTION_EQUAL,
		DEPTH_FUNCTION_LEQUAL,
		DEPTH_FUNCTION_GREATER,
		DEPTH_FUNCTION_NOTEQUAL,
		DEPTH_FUNCTION_GEQUAL,
		DEPTH_FUNCTION_ALWAYS
	};

	enum class CullFaceSide : uint32_t
	{
		CULL_FACE_SIDE_BACK,
		CULL_FACE_SIDE_,
		CULL_FACE_SIDE_FRONT_AND_BACK
	};

	enum class FrontFace : uint32_t
	{
		FRONT_FACE_CW,
		FRONT_FACE_CCW
	};

	enum class StencilFunction : uint32_t
	{
		STENCIL_FUNCTION_NEVER,
		STENCIL_FUNCTION_ALWAYS,
		STENCIL_FUNCTION_LESS,
		STENCIL_FUNCTION_LEQUAL,
		STENCIL_FUNCTION_EQUAL,
		STENCIL_FUNCTION_GREATER,
		STENCIL_FUNCTION_GEQUAL,
		STENCIL_FUNCTION_NOTEQUAL
	};

	enum class StencilOperation : uint32_t
	{
		STENCIL_OPERATION_KEEP,
		STENCIL_OPERATION_ZERO,
		STENCIL_OPERATION_REPLACE,
		STENCIL_OPERATION_INCR,
		STENCIL_OPERATION_DECR,
		STENCIL_OPERATION_INVERT,
		STENCIL_OPERATION_INCR_WRAP,
		STENCIL_OPERATION_DECR_WRAP
	};
}

#endif /* SOURCE_CORE_RENDER_RENDERTYPES_H_ */
