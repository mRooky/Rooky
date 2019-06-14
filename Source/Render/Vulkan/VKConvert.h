/*
 * VKConvert.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCONVERT_H_
#define SOURCE_RENDER_VK_VKCONVERT_H_

#include "VKInline.h"
#include "../../Core/GHI/GHIIndexType.h"
#include "../../Core/GHI/GHIShaderTypes.h"
#include "../../Core/GHI/State/GHIStateEnum.h"
#include <cassert>

namespace VK
{

static inline VkVertexInputRate Convert(GHI::VertexInputRate rate)
{
	switch(rate)
	{
	case GHI::VertexInputRate::VERTEX:
		return VK_VERTEX_INPUT_RATE_VERTEX;
	case GHI::VertexInputRate::INSTANCE:
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
	case GHI::IndexType::U16:
		return VK_INDEX_TYPE_UINT16;
	case GHI::IndexType::U32:
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
	case GHI::ShaderStage::VERTEX:
		return VK_SHADER_STAGE_VERTEX_BIT;
	case GHI::ShaderStage::HULL:
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
	case GHI::ShaderStage::DOMAIN:
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
	case GHI::ShaderStage::GEOMETRY:
		return VK_SHADER_STAGE_GEOMETRY_BIT;
	case GHI::ShaderStage::FRAGMENT:
		return VK_SHADER_STAGE_FRAGMENT_BIT;
	case GHI::ShaderStage::COMPUTE:
		return VK_SHADER_STAGE_COMPUTE_BIT;
	case GHI::ShaderStage::ALL:
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
	case GHI::FrontFace::CW:
		return VK_FRONT_FACE_CLOCKWISE;
	case GHI::FrontFace::CCW:
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
	case GHI::CullFaceSide::NONE:
		return VK_CULL_MODE_NONE;
	case GHI::CullFaceSide::BACK:
		return VK_CULL_MODE_BACK_BIT;
	case GHI::CullFaceSide::FRONT:
		return VK_CULL_MODE_FRONT_BIT;
	case GHI::CullFaceSide::FRONT_AND_BACK:
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
	case GHI::PolygonMode::FILL:
		return VK_POLYGON_MODE_FILL;
	case GHI::PolygonMode::LINE:
		return VK_POLYGON_MODE_LINE;
	case GHI::PolygonMode::POINT:
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
	case GHI::PrimitiveTopology::POINT_LIST:
		return VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
	case GHI::PrimitiveTopology::LINE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST;
	case GHI::PrimitiveTopology::LINE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP;
	case GHI::PrimitiveTopology::TRIANGLE_LIST:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	case GHI::PrimitiveTopology::TRIANGLE_STRIP:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
	case GHI::PrimitiveTopology::TRIANGLE_FAN:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN;
	case GHI::PrimitiveTopology::LINE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::LINE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::TRIANGLE_LIST_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::TRIANGLE_STRIP_WITH_ADJACENCY:
		return VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY;
	case GHI::PrimitiveTopology::PATCH_LIST:
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
	case GHI::CompareOperation::NEVER:
		return VK_COMPARE_OP_NEVER;
	case GHI::CompareOperation::LESS:
		return VK_COMPARE_OP_LESS;
	case GHI::CompareOperation::EQUAL:
		return VK_COMPARE_OP_EQUAL;
	case GHI::CompareOperation::LESS_OR_EQUAL:
		return VK_COMPARE_OP_LESS_OR_EQUAL;
	case GHI::CompareOperation::GREATER:
		return VK_COMPARE_OP_GREATER;
	case GHI::CompareOperation::NOT_EQUAL:
		return VK_COMPARE_OP_NOT_EQUAL;
	case GHI::CompareOperation::GREATER_OR_EQUAL:
		return VK_COMPARE_OP_GREATER_OR_EQUAL;
	case GHI::CompareOperation::ALWAYS:
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
	case GHI::BlendFactor::ZERO:
		return VK_BLEND_FACTOR_ZERO;
	case GHI::BlendFactor::ONE:
		return VK_BLEND_FACTOR_ONE;
	case GHI::BlendFactor::SRC_COLOR:
		return VK_BLEND_FACTOR_SRC_COLOR;
	case GHI::BlendFactor::ONE_MINUS_SRC_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR;
	case GHI::BlendFactor::DST_COLOR:
		return VK_BLEND_FACTOR_DST_COLOR;
	case GHI::BlendFactor::ONE_MINUS_DST_COLOR:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR;
	case GHI::BlendFactor::SRC_ALPHA:
		return VK_BLEND_FACTOR_SRC_ALPHA;
	case GHI::BlendFactor::ONE_MINUS_SRC_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	case GHI::BlendFactor::DST_ALPHA:
		return VK_BLEND_FACTOR_DST_ALPHA;
	case GHI::BlendFactor::ONE_MINUS_DST_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA;
	case GHI::BlendFactor::CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_CONSTANT_ALPHA;
	case GHI::BlendFactor::ONE_MINUS_CONSTANT_ALPHA:
		return VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA;
	case GHI::BlendFactor::SRC_ALPHA_SATURATE:
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
	case GHI::BlendOperation::ADD:
		return VK_BLEND_OP_ADD;
	case GHI::BlendOperation::SUBTRACT:
		return VK_BLEND_OP_SUBTRACT;
	case GHI::BlendOperation::REVERSE_SUBTRACT:
		return VK_BLEND_OP_REVERSE_SUBTRACT;
	case GHI::BlendOperation::MIN:
		return VK_BLEND_OP_MIN;
	case GHI::BlendOperation::MAX:
		return VK_BLEND_OP_MAX;
	default:
		assert(false);
		return VK_BLEND_OP_ADD;
	}
}

}


#endif /* SOURCE_RENDER_VK_VKCONVERT_H_ */
