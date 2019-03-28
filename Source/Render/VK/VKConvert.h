/*
 * VKConvert.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCONVERT_H_
#define SOURCE_RENDER_VK_VKCONVERT_H_

#include "VKInline.h"
#include "State/RenderState.h"
#include <cassert>

namespace VK
{

static inline VkVertexInputRate Convert(Render::VertexInputRate rate)
{
	switch(rate)
	{
	case Render::VertexInputRate::VERTEX_INPUT_RATE_VERTEX:
		return VK_VERTEX_INPUT_RATE_VERTEX;
	case Render::VertexInputRate::VERTEX_INPUT_RATE_INSTANCE:
		return VK_VERTEX_INPUT_RATE_INSTANCE;
	default:
		assert(false);
		return VK_VERTEX_INPUT_RATE_VERTEX;
	}
}

static inline VkIndexType Convert(Render::IndexType type)
{
	switch(type)
	{
	case Render::IndexType::INDEX_TYPE_U16:
		return VK_INDEX_TYPE_UINT16;
	case Render::IndexType::INDEX_TYPE_U32:
		return VK_INDEX_TYPE_UINT32;
	default:
		assert(false);
		return VK_INDEX_TYPE_MAX_ENUM;
	}
}

static inline VkShaderStageFlagBits Convert(Render::ShaderStage stage)
{
	switch (stage)
	{
	case Render::ShaderStage::SHADER_STAGE_VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case Render::ShaderStage::SHADER_STAGE_HULL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case Render::ShaderStage::SHADER_STAGE_DOMAIN:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case Render::ShaderStage::SHADER_STAGE_GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case Render::ShaderStage::SHADER_STAGE_FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case Render::ShaderStage::SHADER_STAGE_COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	case Render::ShaderStage::SHADER_STAGE_ALL_GRAPHICS:
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	default:
		assert(false);
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	}
}

static inline VkFrontFace Convert(Render::FrontFace front)
{
	switch(front)
	{
	case Render::FrontFace::FRONT_FACE_CW:
		return VK_FRONT_FACE_CLOCKWISE;
	case Render::FrontFace::FRONT_FACE_CCW:
		return VK_FRONT_FACE_COUNTER_CLOCKWISE;
	default:
		assert(false);
		return VK_FRONT_FACE_CLOCKWISE;
	}
}

static inline VkCullModeFlags Convert(Render::CullFaceSide cull)
{
	switch(cull)
	{
	case Render::CullFaceSide::CULL_FACE_SIDE_NONE:
		return VK_CULL_MODE_NONE;
	case Render::CullFaceSide::CULL_FACE_SIDE_BACK:
		return VK_CULL_MODE_BACK_BIT;
	case Render::CullFaceSide::CULL_FACE_SIDE_FRONT:
		return VK_CULL_MODE_FRONT_BIT;
	case Render::CullFaceSide::CULL_FACE_SIDE_FRONT_AND_BACK:
		return VK_CULL_MODE_FRONT_AND_BACK;
	default:
		assert(false);
		return VK_CULL_MODE_NONE;
	}
}

static inline VkPolygonMode Convert(Render::PolygonMode polygon)
{
	switch(polygon)
	{
	case Render::PolygonMode::POLYGON_MODE_FILL:
		return VK_POLYGON_MODE_FILL;
	case Render::PolygonMode::POLYGON_MODE_LINE:
		return VK_POLYGON_MODE_LINE;
	case Render::PolygonMode::POLYGON_MODE_POINT:
		return VK_POLYGON_MODE_POINT;
	default:
		assert(false);
		return VK_POLYGON_MODE_FILL;
	}
}

static inline VkPrimitiveTopology Convert(Render::PrimitiveTopology topology)
{
	switch(topology)
	{
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_POINT_LIST:
		return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
	case Render::PrimitiveTopology::PRIMITIVE_TOPOLOGY_PATCH_LIST:
		return VK_PRIMITIVE_TOPOLOGY_PATCH_LIST;
	default:
		assert(false);
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
	}
}

static inline VkCompareOp Convert(Render::CompareOperation operation)
{
	switch(operation)
	{
	case Render::CompareOperation::COMPARE_OP_NEVER:
		return VK_COMPARE_OP_NEVER;
	case Render::CompareOperation::COMPARE_OP_LESS:
		return VK_COMPARE_OP_LESS;
	case Render::CompareOperation::COMPARE_OP_EQUAL:
		return VK_COMPARE_OP_EQUAL;
	case Render::CompareOperation::COMPARE_OP_LESS_OR_EQUAL:
		return VK_COMPARE_OP_LESS_OR_EQUAL;
	case Render::CompareOperation::COMPARE_OP_GREATER:
		return VK_COMPARE_OP_GREATER;
	case Render::CompareOperation::COMPARE_OP_NOT_EQUAL:
		return VK_COMPARE_OP_NOT_EQUAL;
	case Render::CompareOperation::COMPARE_OP_GREATER_OR_EQUAL:
		return VK_COMPARE_OP_GREATER_OR_EQUAL;
	case Render::CompareOperation::COMPARE_OP_ALWAYS:
		return VK_COMPARE_OP_ALWAYS;
	default:
		assert(false);
		return VK_COMPARE_OP_ALWAYS;
	}
}

static inline VkBlendFactor Convert(Render::BlendFactor factor)
{
	switch(factor)
	{
	case Render::BlendFactor::BLEND_FACTOR_ZERO:
		return VK_BLEND_FACTOR_ZERO;
	case Render::BlendFactor::BLEND_FACTOR_ONE:
		return VK_BLEND_FACTOR_ONE;
	case Render::BlendFactor::BLEND_FACTOR_SRC_COLOR:
		return VK_BLEND_FACTOR_SRC_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_DST_COLOR:
		return VK_BLEND_FACTOR_DST_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
	case Render::BlendFactor::BLEND_FACTOR_SRC_ALPHA:
		return VK_BLEND_FACTOR_SRC_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_DST_ALPHA:
		return VK_BLEND_FACTOR_DST_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_CONSTANT_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
	case Render::BlendFactor::BLEND_FACTOR_SRC_ALPHA_SATURATE:
		return VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
	default:
		assert(false);
		return VK_BLEND_FACTOR_ZERO;
	}
}

static inline VkBlendOp Convert(Render::BlendOperation operaion)
{
	switch(operaion)
	{
	case Render::BlendOperation::BLEND_OPERATION_ADD:
		return VK_BLEND_OP_ADD;
	case Render::BlendOperation::BLEND_OPERATION_SUBTRACT:
		return VK_BLEND_OP_SUBTRACT;
	case Render::BlendOperation::BLEND_OPERATION_REVERSE_SUBTRACT:
		return VK_BLEND_OP_REVERSE_SUBTRACT;
	case Render::BlendOperation::BLEND_OPERATION_MIN:
		return VK_BLEND_OP_MIN;
	case Render::BlendOperation::BLEND_OPERATION_MAX:
		return VK_BLEND_OP_MAX;
	default:
		assert(false);
		return VK_BLEND_OP_ADD;
	}
}

}


#endif /* SOURCE_RENDER_VK_VKCONVERT_H_ */
