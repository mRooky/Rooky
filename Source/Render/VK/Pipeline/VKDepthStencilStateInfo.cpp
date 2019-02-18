/*
 * VKDepthStencilStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKDepthStencilStateInfo.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace VK
{

DepthStencilStateInfo::DepthStencilStateInfo(void)
{
	*static_cast<VkPipelineDepthStencilStateCreateInfo*>(this) = Vulkan::Pipeline::DepthStencilStateCreateInfo();
}

DepthStencilStateInfo::~DepthStencilStateInfo(void)
{
}

VkCompareOp DepthStencilStateInfo::Convert(Render::CompareOperation operation)
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

} /* namespace VK */
