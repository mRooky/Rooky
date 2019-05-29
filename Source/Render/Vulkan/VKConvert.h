/*
 * VKConvert.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCONVERT_H_
#define SOURCE_RENDER_VK_VKCONVERT_H_

#include "VKInline.h"
#include "../../Core/GHI/State/GHIStateEnum.h"
#include <cassert>

namespace VK
{

static inline VkVertexInputRate Convert(GHI::VertexInputRate rate)
{
	switch(rate)
	{
	case GHI::VertexInputRate::VERTEX_INPUT_RATE_VERTEX:
		return VK_VERTEX_INPUT_RATE_VERTEX;
	case GHI::VertexInputRate::VERTEX_INPUT_RATE_INSTANCE:
		return VK_VERTEX_INPUT_RATE_INSTANCE;
	default:
		assert(false);
		return VK_VERTEX_INPUT_RATE_VERTEX;
	}
}

static inline VkIndexType Convert(GHI::IndexType type)
{
	switch(type)
	{
	case GHI::IndexType::INDEX_TYPE_U16:
		return VK_INDEX_TYPE_UINT16;
	case GHI::IndexType::INDEX_TYPE_U32:
		return VK_INDEX_TYPE_UINT32;
	default:
		assert(false);
		return VK_INDEX_TYPE_MAX_ENUM;
	}
}

static inline VkShaderStageFlagBits Convert(GHI::ShaderStage stage)
{
	switch (stage)
	{
	case GHI::ShaderStage::SHADER_STAGE_VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case GHI::ShaderStage::SHADER_STAGE_HULL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case GHI::ShaderStage::SHADER_STAGE_DOMAIN:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case GHI::ShaderStage::SHADER_STAGE_GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case GHI::ShaderStage::SHADER_STAGE_FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case GHI::ShaderStage::SHADER_STAGE_COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	case GHI::ShaderStage::SHADER_STAGE_ALL_GRAPHICS:
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	default:
		assert(false);
		return VK_SHADER_STAGE_ALL_GRAPHICS;
	}
}

static inline VkFrontFace Convert(GHI::FrontFace front)
{
	switch(front)
	{
	case GHI::FrontFace::FRONT_FACE_CW:
		return VK_FRONT_FACE_CLOCKWISE;
	case GHI::FrontFace::FRONT_FACE_CCW:
		return VK_FRONT_FACE_COUNTER_CLOCKWISE;
	default:
		assert(false);
		return VK_FRONT_FACE_CLOCKWISE;
	}
}

static inline VkCullModeFlags Convert(GHI::CullFaceSide cull)
{
	switch(cull)
	{
	case GHI::CullFaceSide::CULL_FACE_SIDE_NONE:
		return VK_CULL_MODE_NONE;
	case GHI::CullFaceSide::CULL_FACE_SIDE_BACK:
		return VK_CULL_MODE_BACK_BIT;
	case GHI::CullFaceSide::CULL_FACE_SIDE_FRONT:
		return VK_CULL_MODE_FRONT_BIT;
	case GHI::CullFaceSide::CULL_FACE_SIDE_FRONT_AND_BACK:
		return VK_CULL_MODE_FRONT_AND_BACK;
	default:
		assert(false);
		return VK_CULL_MODE_NONE;
	}
}

static inline VkPolygonMode Convert(GHI::PolygonMode polygon)
{
	switch(polygon)
	{
	case GHI::PolygonMode::POLYGON_MODE_FILL:
		return VK_POLYGON_MODE_FILL;
	case GHI::PolygonMode::POLYGON_MODE_LINE:
		return VK_POLYGON_MODE_LINE;
	case GHI::PolygonMode::POLYGON_MODE_POINT:
		return VK_POLYGON_MODE_POINT;
	default:
		assert(false);
		return VK_POLYGON_MODE_FILL;
	}
}

static inline VkPrimitiveTopology Convert(GHI::PrimitiveTopology topology)
{
	switch(topology)
	{
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_POINT_LIST:
		return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::PRIMITIVE_TOPOLOGY_PATCH_LIST:
		return VK_PRIMITIVE_TOPOLOGY_PATCH_LIST;
	default:
		assert(false);
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
	}
}

static inline VkCompareOp Convert(GHI::CompareOperation operation)
{
	switch(operation)
	{
	case GHI::CompareOperation::COMPARE_OP_NEVER:
		return VK_COMPARE_OP_NEVER;
	case GHI::CompareOperation::COMPARE_OP_LESS:
		return VK_COMPARE_OP_LESS;
	case GHI::CompareOperation::COMPARE_OP_EQUAL:
		return VK_COMPARE_OP_EQUAL;
	case GHI::CompareOperation::COMPARE_OP_LESS_OR_EQUAL:
		return VK_COMPARE_OP_LESS_OR_EQUAL;
	case GHI::CompareOperation::COMPARE_OP_GREATER:
		return VK_COMPARE_OP_GREATER;
	case GHI::CompareOperation::COMPARE_OP_NOT_EQUAL:
		return VK_COMPARE_OP_NOT_EQUAL;
	case GHI::CompareOperation::COMPARE_OP_GREATER_OR_EQUAL:
		return VK_COMPARE_OP_GREATER_OR_EQUAL;
	case GHI::CompareOperation::COMPARE_OP_ALWAYS:
		return VK_COMPARE_OP_ALWAYS;
	default:
		assert(false);
		return VK_COMPARE_OP_ALWAYS;
	}
}

static inline VkBlendFactor Convert(GHI::BlendFactor factor)
{
	switch(factor)
	{
	case GHI::BlendFactor::BLEND_FACTOR_ZERO:
		return VK_BLEND_FACTOR_ZERO;
	case GHI::BlendFactor::BLEND_FACTOR_ONE:
		return VK_BLEND_FACTOR_ONE;
	case GHI::BlendFactor::BLEND_FACTOR_SRC_COLOR:
		return VK_BLEND_FACTOR_SRC_COLOR;
	case GHI::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
	case GHI::BlendFactor::BLEND_FACTOR_DST_COLOR:
		return VK_BLEND_FACTOR_DST_COLOR;
	case GHI::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
	case GHI::BlendFactor::BLEND_FACTOR_SRC_ALPHA:
		return VK_BLEND_FACTOR_SRC_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_DST_ALPHA:
		return VK_BLEND_FACTOR_DST_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_CONSTANT_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
	case GHI::BlendFactor::BLEND_FACTOR_SRC_ALPHA_SATURATE:
		return VK_BLEND_FACTOR_SRC_ALPHA_SATURATE;
	default:
		assert(false);
		return VK_BLEND_FACTOR_ZERO;
	}
}

static inline VkBlendOp Convert(GHI::BlendOperation operaion)
{
	switch(operaion)
	{
	case GHI::BlendOperation::BLEND_OPERATION_ADD:
		return VK_BLEND_OP_ADD;
	case GHI::BlendOperation::BLEND_OPERATION_SUBTRACT:
		return VK_BLEND_OP_SUBTRACT;
	case GHI::BlendOperation::BLEND_OPERATION_REVERSE_SUBTRACT:
		return VK_BLEND_OP_REVERSE_SUBTRACT;
	case GHI::BlendOperation::BLEND_OPERATION_MIN:
		return VK_BLEND_OP_MIN;
	case GHI::BlendOperation::BLEND_OPERATION_MAX:
		return VK_BLEND_OP_MAX;
	default:
		assert(false);
		return VK_BLEND_OP_ADD;
	}
}

}


#endif /* SOURCE_RENDER_VK_VKCONVERT_H_ */
