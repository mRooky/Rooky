/*
 * VKInputAssemblyState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKInputAssemblyStateInfo.h"
#include "VulkanPipeline.h"

#include <cassert>

namespace VK
{

InputAssemblyStateInfo::InputAssemblyStateInfo(void)
{
	*static_cast<VkPipelineInputAssemblyStateCreateInfo*>(this) = Vulkan::Pipeline::InputAssemblyStateCreateInfo();
}

InputAssemblyStateInfo::~InputAssemblyStateInfo(void)
{
}

VkPrimitiveTopology InputAssemblyStateInfo::Convert(Render::PrimitiveTopology topology)
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

} /* namespace VK */
