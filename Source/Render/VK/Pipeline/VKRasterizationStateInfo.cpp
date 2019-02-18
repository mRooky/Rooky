/*
 * VKRasterizationState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKRasterizationStateInfo.h"

#include "VulkanPipeline.h"

#include <cassert>

namespace VK
{

RasterizationStateInfo::RasterizationStateInfo(void)
{
	*static_cast<VkPipelineRasterizationStateCreateInfo*>(this) = Vulkan::Pipeline::RasterizationStateCreateInfo();
}

RasterizationStateInfo::~RasterizationStateInfo(void)
{
}

VkFrontFace RasterizationStateInfo::Convert(Render::FrontFace front)
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

VkCullModeFlags RasterizationStateInfo::Convert(Render::CullFaceSide cull)
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

VkPolygonMode RasterizationStateInfo::Convert(Render::PolygonMode polygon)
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

} /* namespace VK */
